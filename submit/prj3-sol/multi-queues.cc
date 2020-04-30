#include <iostream>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <memory>

#include "job.hh"
#include "command.hh"
#include "command-stream.hh"

//using namespace Command::Cmd;

template <typename T> 
class heap {
	private:
		typedef bool (*comparator)(const T&, const T&);
		comparator cmp;
		void swp(std::vector<T>& heap, int a, int b){
			const T temp = heap[a];
			heap[a] = heap[b];
			heap[b] = temp;
		}

		void sift_down(std::vector<T>& heap, int i){
			if(i*2+1 > heap.size()){
					return;
			}
			int ind = i;

			if(i*2+1 > heap.size()-1) { return;}
			if(i*2+2 > heap.size()-1){
				if(cmp(heap[i*2+1], heap[ind])){
					ind = i*2+1;
				}
			}
			else {
				if(cmp(heap[i*2+1], heap[ind]) == false){
					ind = i*2+1;
				}
				if(cmp(heap[i*2+1], heap[ind]) == false){
					ind = i*2+2;
				}
			}
			if(ind != i){
				swp(heap, ind, i);
				sift_down(heap, ind);
			}
		}
	public:
		heap(comparator cmp) : cmp(cmp) {}
		void heapify(std::vector<T>& heap) {
			for(int i = heap.size()/2; i > -1; i++){
				sift_down(heap, i);
			}
		}
		const T pop(std::vector<T>& heap){
			const T ret = heap[0];
			heap[0] = heap.back();
			heap.pop_back();
			sift_down(heap,0);
			return ret;
		}
		void push(std::vector<T>& heap, T el){
			heap.push_back(el);
			int ind = heap.size() - 1;
			while(cmp(heap[ind], heap[(ind-1)/2])){
				swp(heap, ind, (ind-1)/2);
				ind = (ind-1)/2;
			}
		}
		bool cmp_gtr(const Job& a, const Job& b){
			return a.priority0 > b.priority0;
		}

		bool cmp_less(const Job& a, const Job& b){
			return a.priority1 < b.priority1;
		}

		// do i even need enter and leave if i have push and pop? maybe not
		// prof -> yes, they call push/pop on correct heaps
		
};

	bool cmp_gtr(const Job& a, const Job& b){
		return a.priority0 > b.priority0;
	}

	bool cmp_less(const Job& a, const Job& b){
		return a.priority0 < b.priority0;
	}

	void enter(std::vector<T>& heap, const Job& job){
		heap.push(heap, job);
	}

	void leave(std::vector<T>& heap1){
		// check if empty
		if(heap1.size() == 0){
			return;
		}
		else {
		// pop from vector
		pop(heap1);
		}
	}

	const T move(std::vector<T>& heap0, std::vector<T>& heap1){
		// check if empty
		if(heap0.size() == 0){
			return;
		}
		else {
		// arrange q0 so we know we're getting rid of the right job
		Job& highest_priority = heap0.pop(heap0);

		// push highest priority job onto q1 and then rearrange
		push(heap1, highest_priority);
		}
	}



//std::unique_ptr<Command> Command::read(std::istream& in);

int main(int argc, char* argv[]){

	if(argc != 2){
		std::cerr << "usage: " << argv[0] << " FILE_PATH" << std::endl;
		std::exit(1);
	}
	// TODO: compare by lexographic if same priority

	// read input
	CommandStream commandIn(argv[1]); // create command stream
	
	// create the two heaps (should be inside class, not in main)
	heap<Job> heap0(cmp_gtr);
	heap<Job> heap1(cmp_less);

	// make the class
	// that makes the heaps
	// read each commad
	// call enter, move, or leave
	// 	those functions call enqueue or dequeue

	// put two heaps in a class, then call enter, move, leave functions (implement)
	// enter -> enqueue on queue0
	// move -> dequeue on queue0, enqueue on queue1
	// leave -> dequeue on queue1

	// EnterCommand has cmd field as well as job field
	// Move and leave do NOT have job field
	for(std::unique_ptr<Command> commandP = commandIn.next(); commandP != nullptr; commandP = commandIn.next()){		
		Command cmd = *commandP;


		// special class for EnterCommand because only command that contains job
		if(cmd.cmd == Command::Cmd::ENTER){
			EnterCommand* enterP = dynamic_cast<EnterCommand*>(commandP.get());
			Job job = enterP->job;
			// now just need to enter the job into the system (enqueue)
			heap<Job>::enter(heap0,&job);	
			
		}
		else if(cmd.cmd == Command::Cmd::MOVE){
			// do something
		}
		else if(cmd.cmd == Command::Cmd::MOVE){
		}
		else{
			std::cout << "Invalid command. Usage: 'COMMAND ID PRIORITY0 PRIORITY1'" << std::endl;
		}
	}	
	return 0;
}



