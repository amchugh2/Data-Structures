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

using namespace Command::Cmd;

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
			return a.priority0 < b.priority0;
		}

		// do i even need enter and leave if i have push and pop? maybe not
		/*
		void enter(std::vector<T>& heap, const Job& job){
			heap<Job> heap.template queue0(cmp_gtr);
			queue0.heapify(heap);
			queue0.push(heap, job);
		}

		void leave(std::vector<T>& heap1){
			// check if empty
			if(heap1.size() == 0){
				break;
			}
			else {
			// pop from vector
			pop(heap1, job);
			// select comparator
			heap<Job> queue1(cmp_gtr);
			// heapify
			queue1.heapify(heap);
			}
		}

		*/

		const T move(std::vector<T>& heap0, std::vector<T>& heap1){
			// check if empty
			if(heap0.size() == 0){
				return;
			}
			else {
			// arrange q0 so we know we're getting rid of the right job
			heap<Job> queue0(cmp_gtr);
			queue0.heapify(heap0);
			Job& highest_priority = queue0.pop(heap0);
			// push highest priority job onto q1 and then rearrange
			push(heap1, highest_priority);
			heap<Job> queue1(cmp_less);
			queue1.heapify(heap1);
			}
		}

};

// forward declarations
static Command::Cmd stringToCmd(std::string str);
static std::string cmdToString(Command::Cmd cmd);

/*
std::string cmdToString(Command cmd){
	switch(cmd) {
		case Command::Cmd::ENTER:
			return "enter";
		case Command::Cmd::LEAVE:
			return "leave";
		case Command::Cmd::MOVE:
			return "move";
		default:
			assert(false);
	}
}
*/


//std::unique_ptr<Command> Command::read(std::istream& in);

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: " << argv[0] << " FILE_PATH" << std::endl;
		std::exit(1);
	}

	CommandStream commandIn(argv[1]); // create command string
	for(std::unique_ptr<Command> commandP = commandIn.next(); commandP != nullptr; commandP = commandIn.next()){
		Command::Cmd cmd = *commandP;
		if(cmdToString(*cmd) == "enter"){
			std::cout << *commandP << std::endl;
		}
	}	
	return 0;
}



