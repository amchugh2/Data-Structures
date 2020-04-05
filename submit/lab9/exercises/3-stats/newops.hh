#ifndef NEWOPS_HH_
#define NEWOPS_HH_

#include "ops.hh"

class newOps : public Ops {
	int compare_count;
	int swap_count;

	virtual int compare(int a, int b) {
		Ops::compare(a,b);
		return compare_count+=1;
	}
	virtual void swap(int a[], int i, int j) {
		Ops::swap(a, i, j);
		swap_count+=1;
	}
};

#endif


