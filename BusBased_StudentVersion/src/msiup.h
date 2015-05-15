/************************************************************
			Course 		: 	CSC/ECE506
			Source 		:	msiup.h
			Instructor	:	Ed Gehringer
			Email Id	:	efg@ncsu.edu
------------------------------------------------------------
	© Please do not replicate this code without consulting
		the owner & instructor! Thanks!
*************************************************************/  
class MSI_upgrade : public Cache {
 public:
	MSI_upgrade(int s, int a, int b, int p , int pn)
				: Cache(s, a, b, p, pn) {};
	~MSI_upgrade() {};
	void PrRd(ulong addr, int processorNumber);
	void PrWr(ulong addr, int processorNumber);
	cache_line *allocate_line(ulong addr);
	void BusRd(ulong addr);
	void BusUpgr(ulong addr);
	void BusRdX(ulong addr);
};
