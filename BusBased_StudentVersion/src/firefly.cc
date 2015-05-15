/************************************************************
			Course 		: 	CSC456
			Source 		:	firefly.cc
			Instructor	:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------
	© Please do not replicate this code without consulting
		the owner & instructor! Thanks!
*************************************************************/ 	     
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "main.h"
#include "firefly.h"
using namespace std;

void Firefly::PrRd(ulong addr, int processor_number) {
}

void Firefly::PrWr(ulong addr, int processor_number) {
}

cache_line * Firefly::allocate_line(ulong addr) 
{ 
	cache_line *victim = NULL;
	return victim;
}

void Firefly::BusRd(ulong addr) {
}

void Firefly::BusWr(ulong addr) {
}
