/************************************************************
			Course		: 	CSC/ECE506
			Source 		:	fbv.cc
			Owner		:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------*
	© Please do not replicate this code without consulting
		the owner & instructor! Thanks!
*************************************************************/
#include "fbv.h"

void FBV::add_sharer_entry(int proc_num){
	bit[proc_num] = true;
}

void FBV::remove_sharer_entry(int proc_num){
	// YOUR CODE HERE
	// Reset the bit vector entry
}

int FBV::is_cached(int num_proc){
	// YOUR CODE HERE
	// Check bit vector for any set bit. 
	// If set, return 1, else send 0
	return 0; // Returning 0 to avoid compilation errors.
}

void FBV::sendInt_to_sharer(ulong addr, int num_proc, int proc_num){
	// YOUR CODE HERE
	//
	// Invoke the sendInt function defined in main 
	// for all the processors except for proc_num
	// Make sure that you check the FBV to see if the 
	// bit is set
}

void FBV::sendInv_to_sharer(ulong addr, int num_proc, int proc_num){
	// YOUR CODE HERE
	//
	// Invoke the sendInv function defined in main 
	// for all the processors except for proc_num
	// Make sure that you check the FBV to see if the 
	// bit is set
}

