#include <iostream>

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>

#include "job.hh"

class MaxHeap {
public:
  MaxHeap(Job heapArray[], int nElements, int size) :
    heap(heapArray), nAlloc(size), nElements(nElements)
  {
    buildHeap();
  }

  void enqueue(Job job) {
    assert(nElements < nAlloc && "heap is full");
    heap[nElements++] = job; //add value at end
    for (int pos = nElements - 1; //pos of added value
	 pos != 0 && heap[pos] > heap[parent(pos)];
	 pos = parent(pos)) {
      swap(pos, parent(pos));
    }
  }

  int dequeue() {
    assert(nElements > 0 && "heap is empty");
    int value = heap[0];
    heap[0] = heap[nElements - 1]; //put last element at root
    --nElements; //delete it
    if (nElements > 0) siftDown(0);  //move it to correct position
    return value;
  }

  int size() { return nElements; }

private:
  Job* heap; 
  int nAlloc;    //max # of elements in heap
  int nElements; //# of currently allocated element in heap

  /** Heapify heap [0, nElements). */
  void buildHeap() {
    //move internal nodes down if necessary
    for (int i = nElements/2 - 1; i >= 0; --i) {
      siftDown(i);
    }
  }

  /** Move element at pos down in the tree until it is greater
   *  than either of its two children.
   *  When it is necessary to move down, prefer to move down
   *  into subtree with the greater root. 
   */
  void siftDown(int pos) {
    assert(0 <= pos && pos < nElements);
    while (!isLeaf(pos)) {
      int leftKidPos = leftChild(pos);
      //there must be a left kid since pos is not a leaf
      assert(0 <= leftKidPos && leftKidPos < nElements);
      int rightKidPos = rightChild(pos);
      int maxKidPos =
	(rightKidPos >= 0 && heap[rightKidPos] > heap[leftKidPos])
	? rightKidPos
	: leftKidPos;
      if (heap[pos] >= heap[maxKidPos]) return;
      swap(pos, maxKidPos);
      pos = maxKidPos;
    }
  }

  void swap(int pos1, int pos2) {
    assert(0 <= pos1 && pos1 < nElements);
    assert(0 <= pos2 && pos2 < nElements);
    int tmp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = tmp;
  }

  //tree accessors
  bool isLeaf(int pos) const {
    return (pos >= nElements/2) && (pos < nElements);
  }

  int leftChild(int pos) {
    return (2*pos + 1 < nElements) ? 2*pos + 1 : -1;
  }

  int rightChild(int pos) {
    return (2*pos + 2 < nElements) ? 2*pos + 2 : -1;
  }

  int parent(int pos) {
    return (pos > 0) ? (pos - 1)/2 : -1;
  }

  friend std::ostream& operator<<(std::ostream& out, const MaxHeap& heap);
};

std::ostream&
operator<<(std::ostream& out, const MaxHeap& heap) {
  out << "[ ";
  for (int i = 0; i < heap.nElements; i++) {
    out << heap.heap[i] << " ";
  }
  out << "]";
  return out;
}

enum { MAX_HEAP_SIZE = 16 };

/** prefix of  argv[] elements which are ints used to 
 *  to initialize heap; if remaining arg starts is
 *  +VAL, then VAL enqueued onto heap; if "-", then
 *  a value is dequeued from heap.
 */
int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " INT... [+INT|-]" << std::endl;
    exit(1);							       
  }
  std::ostream& out = std::cout;
  int array[MAX_HEAP_SIZE];
  int argvIndex;
  int nElements = 0;
  for (argvIndex = 1; argvIndex < argc; argvIndex++) {
    const char* arg = argv[argvIndex];
    if (!isdigit(arg[0])) break;
    assert(nElements < MAX_HEAP_SIZE && "too many initial elements");
    array[nElements++] = atoi(arg);
  }
  MaxHeap heap(array, nElements, MAX_HEAP_SIZE);
  out << "initial heap: " << heap << std::endl;
  for (; argvIndex < argc; ++argvIndex) {
    const char* arg = argv[argvIndex];
    if (arg[0] == '+') {
      int value = atoi(&arg[1]);
      heap.enqueue(value);
      out << "enqueued " << value << ": " << heap << std::endl;
    }
    else {
      assert(strcmp(arg, "-") == 0 && "invalid argv[] value");
      int value = heap.dequeue();
      out << "dequeued " << value << ": " << heap << std::endl;
    }
  }
}

