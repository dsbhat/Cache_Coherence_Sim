/************************************************************
			Course 		: 	CSC/ECE506
			Source 		:	mesi.h
			Instructor	:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------
	© Please do not replicate this code without consulting
		the owner & instructor! Thanks!
*************************************************************/  
class MESI : public Cache {
 public:
	MESI(int s, int a, int b, int p , int pn): 
			Cache(s, a, b, p, pn) {};
	~MESI() {};
	void PrRd(ulong addr, int processor_number);
	void PrWr(ulong addr, int processor_number);
	cache_line *allocate_line(ulong addr);
	void BusRd(ulong addr);
	void BusRdX(ulong addr);
	void BusUpgr(ulong addr);
};

