/************************************************************
			Course 		: 	CSC456
			Source 		:	cache.h
			Instructor	:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------
	Version	|	Programmer		|	Change Description		
------------------------------------------------------------
		1.0	|	Ahmad Samih & 	|
			|	Yan Solihin		|	Initial Version
		2.0	|	Ed Gehringer	|	Revised for Fall 2014
			|					|	CSC456
------------------------------------------------------------
	© Please do not replicate this code without consulting 	
		the owner & instructor! Thanks!						
*************************************************************/

#ifndef CACHE_H
#define CACHE_H
#include <cmath>
#include <iostream>

typedef unsigned long ulong;
typedef unsigned char uchar;
typedef unsigned int uint;

/****add new states, based on the protocol****/
enum cache_state {
	I, // invalid
	E, // exclusive
	M, // modified
	Sc, // shared clean
	Sm, // shared modified
	V, // valid exclusive
	S, // shared
	D, // dirty
};

class cache_line {

protected:
   ulong tag;
   cache_state State;   
   ulong seq;
   int cmp_thres_counter;
 
public:
   cache_line()							{ tag = 0; State = I; }
   ulong get_tag()       				{ return tag; }
   cache_state get_state()				{ return State;}
   ulong get_seq()       				{ return seq; }
   void set_seq(ulong Seq)				{ seq = Seq;}
   void set_state(cache_state state)	{ State = state;}
   void set_thres_counter(int thr_count){ cmp_thres_counter = thr_count;}
   int get_thres_counter()				{ return cmp_thres_counter;}
   void dec_thres_counter()				{ cmp_thres_counter--;}
   void set_tag(ulong a)				{ tag = a;}
   bool valid()        					{ return ((State) != I); }
   
};

class Cache {
protected:
	ulong size, line_size, assoc;
	ulong sets, log2_sets, log2_blk, tag_mask, num_lines, num_processor;
	ulong reads, read_misses, writes, write_misses, write_backs;
	ulong memory_transactions, cache2cache;
	
	int cache_num, num_processors;
	cache_line **cache;

  	ulong tag_field(ulong addr)		{ return (addr >> (log2_blk) );}
	ulong index_field(ulong addr)	{ return ((addr >> log2_blk) & tag_mask);}
	ulong calc_addr4tag(ulong tag) 	{ return (tag << (log2_blk));}
public:
    ulong current_cycle;  
	ulong bus_reads, bus_readxs, bus_upgrades, bus_writes;
	
	Cache(int, int, int, int, int);
    virtual ~Cache() { delete cache;}

    cache_line * find_line_to_replace(ulong addr);
    virtual cache_line * allocate_line(ulong) = 0;
    cache_line * find_line(ulong addr);
    cache_line * get_line_to_evict(ulong);

    ulong get_read_misses()		{return read_misses;} 
	ulong get_write_misses()	{return write_misses;} 
    ulong get_reads()			{return reads;}   
	ulong get_writes()			{return writes;}
    ulong get_write_backs()		{return write_backs;}
    ulong get_mem_txns() 		{return memory_transactions;}
    ulong get_cache2cache() 	{return cache2cache;}
	
	//Bus Statistics
	ulong get_bus_reads() 		{return bus_reads;}
	ulong get_bus_readxs()		{return bus_readxs;}
	ulong get_bus_upgrades() 	{return bus_upgrades;}
	ulong get_bus_writes() 		{return bus_writes;}
    void write_back(ulong)   	{write_backs++;}
    void print_stats(int,int);
    void update_LRU(cache_line *);
	
	// Methods for Processor Operations
    virtual void PrRd(ulong, int) = 0;
    virtual void PrWr(ulong, int) = 0;
	
	// Methods for Bus-Based Symmetric Multiprocessor
	virtual void BusRd(ulong) 	{return;};
    virtual void BusRdX(ulong) 	{return;}; 
    virtual void BusUpgr(ulong)	{return;};
    virtual void BusWr(ulong)	{return;};
};

// Abstract Factory Creational Pattern to create the caches based on the protocol
class cache_factory {
public:
    enum protocol_name{
		Write_through,
		Firefly,
		MSI,
		MSI_upgrade,
		MESI,
		MOESI
	};

    static Cache* create_cache( int protocol_no, int size, int assoc, 
								int block_size, int num_processor, 
								int processor_num);
};
#endif
