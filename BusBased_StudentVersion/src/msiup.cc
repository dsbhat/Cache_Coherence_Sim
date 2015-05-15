/************************************************************
			Course 		: 	CSC456
			Source 		:	msiup.cc
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
#include "msiup.h"

void MSI_upgrade::PrRd(ulong addr, int processor_number) {
}

void MSI_upgrade::PrWr(ulong addr, int processor_number) {
}

cache_line * MSI_upgrade::allocate_line(ulong addr) { 
    cache_line *victim = NULL;;
	return victim;
}

void MSI_upgrade::BusRd(ulong addr) {
}

void MSI_upgrade::BusRdX(ulong addr) {
}

void MSI_upgrade::BusUpgr(ulong addr) {	
}
