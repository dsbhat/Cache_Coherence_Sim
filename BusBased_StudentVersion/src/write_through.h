/************************************************************
			Course 		: 	CSC/ECE506
			Source 		:	write_through.h
			Instructor	:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------
	© Please do not replicate this code without consulting
		the owner & instructor! Thanks!
*************************************************************/ 

class Write_through : public Cache{
 public:
	Write_through(int s, int a, int b, int p, int pn):
		Cache(s, a, b, p, pn) {};
	~Write_through() {};
	void PrRd(ulong addr, int processor_number);
	void PrWr(ulong addr, int processor_number);
	cache_line *allocate_line(ulong addr);
	void BusRd(ulong addr);
	void BusWr(ulong addr);
};
