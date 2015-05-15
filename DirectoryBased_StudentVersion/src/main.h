/************************************************************
			Course		: 	CSC/ECE506
			Source 		:	main.h
			Owner		:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------*
	© Please do not replicate this code without consulting
		the owner & instructor! Thanks!
*************************************************************/
#ifndef MAIN_H
#define MAIN_H
typedef unsigned long ulong;
typedef unsigned char uchar;
typedef unsigned int uint;
//
void print_input_format();
void create_processor_cache(int np,int s,int a,int b,
							int p, ulong d_s, int t);
int sharers(ulong addr);
void simulate_caches(char *fname);
void sendInt(ulong addr, int proc_num);
void sendInv(ulong addr, int proc_num);
//
#endif