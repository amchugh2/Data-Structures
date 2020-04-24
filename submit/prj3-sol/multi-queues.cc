#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>

class Heap {
	public Heap(int heapArray[], int nElements, int size):
		heap(heapArray), nAlloc(size), nElements(nElements)
	{
		buildHeap();
	}

	void enqueue(int value){
		assert(nElements < nAlloc && "heap is full");
		heap[nELements++] = value; // at value at end
		for(int pos = nElements - 1);
			pos != 0 && heap[pos] > heap[parent(pos)];
			pos = parent(pos))i


