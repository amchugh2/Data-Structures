#ifndef NEWOPS_HH_
#define NEWOPS_HH_

#include "ops.hh"

class newOps : public Ops {
public:
	int compare_count;
	int swap_count;

	virtual int compare(int a, int b) override {
		compare_count+=1;
		return Ops::compare(a,b);
	}
	virtual void swap(int a[], int i, int j) override {
		swap_count+=1;
		Ops::swap(a, i, j);
	}
};

#endif


