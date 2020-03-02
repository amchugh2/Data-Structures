#include <iostream>
#include <cstring>

void main(int argc, char *argv[]){
	// Error checking
	if(argc < 2){
		std::cerr << "usage: ./nums [-a] INTS_FILE_PATH\n";
	}

	std::ifstream in(argv[2]);
	
	if(!in.good(){
		std::cerr << "cannot read " << argv[2] << ": No such file or directory\n";
	}


}



