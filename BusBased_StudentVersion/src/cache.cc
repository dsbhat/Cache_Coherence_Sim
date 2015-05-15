/************************************************************
			Course 		: 	CSC/ECE506
			Source 		:	cache.cc
			Instructor	:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------
	Version	|	Programmer		|	Change Description		
------------------------------------------------------------
		1.0	|	Ahmad Samih & 	|
			|	Yan Solihin		|	Initial Version
		2.0	|	Ed Gehringer	|	Revised for Spring 2015
			|					|	CSC/ECE506
------------------------------------------------------------
	© Please do not replicate this code without consulting 	
		the owner & instructor! Thanks!						
*************************************************************/
		     
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
#include "cache.h"
#include "msi.h"
#include "mesi.h"
#include "moesi.h"
#include "msiup.h"
#include "firefly.h"
#include "write_through.h"

Cache::Cache(int s, int a, int b, int p, int pn){
  ulong i, j;
   // counters
   reads = read_misses = writes = 0; 
   write_misses = write_backs = current_cycle = 0;
   memory_transactions = cache2cache = 0;
         
   // simulation parameters
   num_processor	= (ulong) (p);
   size	      		= (ulong)(s);
   line_size   		= (ulong)(b);
   assoc      		= (ulong)(a);   
   sets	      		= (ulong)((s/b)/a);
   num_lines   		= (ulong)(s/b);
   log2_sets   		= (ulong)(log2(sets));   
   log2_blk    		= (ulong)(log2(b));
   cache_num		= pn;
   num_processors	= p;

   tag_mask =0;
   for (i=0;i<log2_sets;i++)
   {
	tag_mask <<= 1;
	tag_mask |= 1;
   }
   
   /** Create a 2-dimensional cache, sized as cache[sets][assoc] **/ 
   cache = new cache_line*[sets];
   for (i=0; i<sets; i++)
   {
      cache[i] = new cache_line[assoc];
      for (j=0; j<assoc; j++) 
      {
		cache[i][j].set_state(I);
		cache[i][j].set_thres_counter(0);
      }
   }	  
}

/* Look up line */
cache_line * Cache::find_line(ulong addr){
   ulong i, j, tag, pos;
   
   pos = assoc;
   tag = tag_field(addr);
   i   = index_field(addr);
  
   for (j=0; j<assoc; j++)
    if (cache[i][j].valid())
	if (cache[i][j].get_tag() == tag) {
	    pos = j; break; 
	}
    if (pos == assoc)
	return NULL;
    else
	return &(cache[i][pos]); 
}

/* Upgrade LRU line to be MRU line */
void Cache::update_LRU(cache_line *line){
  line->set_seq(current_cycle);  
}

/* Return an invalid line, if any; otherwise return the LRU line */
cache_line * Cache::get_line_to_evict(ulong addr){
   ulong i, j, victim, min;

    victim = assoc;
    min	  = current_cycle;
    i	  = index_field(addr);

    for (j=0; j<assoc; j++){
       if (!cache[i][j].valid()) 
		return &(cache[i][j]);
    }   
    for (j=0; j<assoc; j++)   {
		if (cache[i][j].get_seq() <= min) {
			victim = j; 
			min = cache[i][j].get_seq();
		}
    } 
    assert(victim != assoc);
    return &(cache[i][victim]);
}
// Find a victim, and move it to the MRU position
cache_line *Cache::find_line_to_replace(ulong addr){
   cache_line * victim = get_line_to_evict(addr);
   update_LRU(victim);
   return (victim);
}
// Factory Pattern to create the cache, based on the 
// protocol number input through the command prompt
Cache* cache_factory::create_cache(int protocol_no, int size, int assoc,
									int block_size, int num_processors,
									int processor_num){
	 switch ((protocol_name) protocol_no) {
			case Write_through:
				return new Write_through::Write_through(size, assoc,
								block_size, num_processors, processor_num);								
			case Firefly:
				return new Firefly::Firefly(size, assoc, block_size,
				                          num_processors, processor_num);
			case MSI:
				return new MSI::MSI(size, assoc, block_size,
									num_processors, processor_num);
			case MSI_upgrade:
				return new MSI_upgrade::MSI_upgrade(size, assoc,block_size,
							num_processors, processor_num);	
			case MESI:
				return new MESI::MESI(size, assoc, block_size,
									num_processors, processor_num);
			case MOESI:
				return new MOESI::MOESI(size, assoc, block_size,
									num_processors, processor_num);									
			default:
				return NULL;
	}
}
//
void Cache::print_stats(int processor_number,int protocol){ 
	int count = 1;
		cout << "============ Simulation results (Cache ";
	cout << processor_number << ") ============ " << endl;
	cout << left << setw(2) << count++ << setw(40) <<". number of reads: ";
	cout << (int) get_reads();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of read misses: ";
	cout << (int) get_read_misses();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of writes: ";
	cout << (int) get_writes();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of write misses:";
	cout << (int) get_write_misses();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". total miss rate: ";
	printf("%.6lf", ((double) get_read_misses() + 
					(double) get_write_misses()) / ((double) get_reads()
					+ (double) get_writes()));
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of writebacks: ";
	cout << (int) get_write_backs();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of memory transactions: ";
	cout << (int) get_mem_txns();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of cache-to-cache transfers: ";
	cout<<(int)get_cache2cache();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of BusRds issued: ";
	cout << (int) get_bus_reads();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of BusWrs issued: ";
	cout << (int) get_bus_writes();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of BusRdXs issued: ";
	cout << (int) get_bus_readxs();
	cout << endl;
	cout << setw(2) << count++ << setw(40) <<". number of BusUpgrs issued: ";
	cout << (int) get_bus_upgrades();
	cout << endl;
}
