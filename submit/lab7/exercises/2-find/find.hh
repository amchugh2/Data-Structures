#ifndef OUT_HH_
#define OUT_HH_

#include <vector>

/** Output a line containing "FOUND" if arg is found in [begin, end),
 *  otherwise output "NOT FOUND"..
 */
template <typename Iterator>
void loopFn(Iterator begin, Iterator end, int arg) {
  //@TODO
  bool found = false;
  for(auto p = begin; p != end; ++p){
	  if(*p == arg){
		  found = true;
	  }
  }
  if(found == true){
	  std::cout << "FOUND";
  }
  else{
	  std::cout << "NOT FOUND";
  }	  
}

/** Exactly like loopFn() but no loops should be used */
template <typename Iterator>
void noLoopFn(Iterator begin, Iterator end, int arg) {
	auto find = std::find(begin, end, arg);
	if(find != end){
		std::cout << "FOUND";
	}
	else{
		std::cout << "NOT FOUND";
	}
}

#endif //ifndef OUT_HH_
