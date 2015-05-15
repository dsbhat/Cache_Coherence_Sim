/************************************************************
			Course 		: 	CSC/ECE506
			Source 		:	write_through.cc
			Instructor	:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------
	© Please do not replicate this code without consulting
		the owner & instructor! Thanks!
*************************************************************/ 
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
using namespace std;
#include "main.h"
#include "write_through.h"

void Write_through::PrRd(ulong addr, int processor_number) {
    cache_state state;
	// Per-cache global counter to maintain LRU order among 
	// cache ways, updated on every cache access
	current_cycle++; 
    reads++;
    cache_line * line = find_line(addr);
    if (line == NULL) { 
		// This is a miss 
		read_misses++;
		cache_line *newline = allocate_line(addr);
		memory_transactions++;
		// State I --> V 
		newline->set_state(V);
		// Read miss --> BusRd		
		bus_reads++;
		sendBusRd(addr, processor_number);
    }
    else { 
		// The block is cached
		state=line->get_state();
		if (state == I){
			// The block is cached, but in invalid state.
			// Hence Read miss
			read_misses++;
			line->set_state(V);
			bus_reads++;
			sendBusRd(addr, processor_number);
		}
		else{
			update_LRU(line);
		}
	}
}

void Write_through::PrWr(ulong addr, int processor_number) {
    cache_state state;
    current_cycle++;
    writes++;
    cache_line * line = find_line(addr);
    if (line == NULL || line->get_state() == I){ 
		/* This is a miss */
		write_misses++;
 		memory_transactions++;
		bus_writes++;
		sendBusWr(addr, processor_number);
    }
    else 
	{
		/* Since it's a hit, update LRU and update state */
		update_LRU(line);
 		state=line->get_state();
		
		if (state == V){
			memory_transactions++;
			bus_writes++;
			sendBusWr(addr, processor_number);
		}
		else{
			cout << "Error in State" << endl;
		}
	}
}

cache_line * Write_through::allocate_line(ulong addr) { 
    ulong tag;
    cache_state state;
   
    cache_line *victim = find_line_to_replace(addr);
    assert(victim != 0);
    state = victim->get_state();

    tag = tag_field(addr);   
    victim->set_tag(tag);
    victim->set_state(I);	 

// Note that this cache line has already been upgraded to MRU
//  in the previous function (find_line_to_replace)
    return victim;
}
//
void Write_through::BusRd(ulong addr) {
    cache_state state;    
    cache_line * line=find_line(addr);
    if (line!=NULL) { 	
		// If true, it was a hit, so change state appropriately
		state = line->get_state();
		if (state!= V)
			cout << "Error in State - BusRd" << endl;
	}
}
//
void Write_through::BusWr(ulong addr) {
    cache_line * line=find_line(addr);
    if (line!=NULL)	{ 
		// If true, it was a hit, so change state appropriately
		line->set_state(I);
	}
}
