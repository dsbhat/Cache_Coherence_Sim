/************************************************************
			Course 		: 	CSC/ECE506
			Source 		:	mesi.cc
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

#include "cache.h"
#include "main.h"
#include "io_function.h"
#include "mesi.h"
//
void MESI::PrRd(ulong addr, int processor_number) 
{
	
}
//
void MESI::PrWr(ulong addr, int processor_number) 
{
   
}
//
cache_line * MESI::allocate_line(ulong addr) { 
	cache_line *victim = NULL;	
    return victim;
}
//
void MESI::BusRd(ulong addr) 
{
    
}
//
void MESI::BusRdX(ulong addr) 
{
    
}
//
void MESI::BusUpgr(ulong addr) 
{
   
}
