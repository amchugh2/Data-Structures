#include <iostream>
#include <cstring>
#include <istream>

void main(int argc, char *argv[]){
	// Error checking
	if(argc < 2){
		std::cerr << "usage: ./nums [-a] INTS_FILE_PATH\n";
		return EXIT_FAILURE;
	}

	if(argv[1] != "-a"){
		std::cerr << "Option can only be [-a]\n";
		return EXIT_FAILURE;
	}

	std::ifstream in(argv[2]);
	
	if(!in.good(){
		std::cerr << "cannot read " << argv[2] << ": No such file or directory\n";
	}
	
	using TestType = int;
	int i;
	// Create seq test type
	Seq<TestType> seq;
	
	while(in.good()){
		in >> i;
		


       	


}



