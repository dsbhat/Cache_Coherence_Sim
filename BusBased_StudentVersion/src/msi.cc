/************************************************************
			Course 		: 	CSC456
			Source 		:	msi.cc
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
#include "msi.h"

void MSI::PrRd(ulong addr, int processor_number) {
    
}

void MSI::PrWr(ulong addr, int processor_number) {
    
}

cache_line * MSI::allocate_line(ulong addr) { 
    cache_line *victim = NULL;
    return victim;
}
//
void MSI::BusRd(ulong addr) {
}
//
void MSI::BusRdX(ulong addr) {
}
