/************************************************************
			Course 		: 	CSC/ECE506
			Source 		:	firefly.h
			Instructor	:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------
	© Please do not replicate this code without consulting
		the owner & instructor! Thanks!
*************************************************************/ 	 

class Firefly : public Cache {
 public:
	Firefly(int s, int a, int b, int p , int pn)
		: Cache(s, a, b, p, pn) {};
	~Firefly() {};
	void PrRd(ulong addr, int processorNumber);
	void PrWr(ulong addr, int processorNumber);
	cache_line *allocate_line(ulong addr);
	void BusRd(ulong addr);
	void BusWr(ulong addr);
};
