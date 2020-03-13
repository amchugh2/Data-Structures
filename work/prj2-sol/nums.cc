#include <iostream>
#include <cstring>
#include <istream>
#include <fstream>
#include "seq.hh"

using namespace std;

class Nums : public Seq {
	void read_args(char *file){
		string i;
		if(argv[0] == "-a"){
			ifstream in(argv[1]);
		}
		else{
			ifstream in(argv[0]);
		}
		in >> i;
		cout << i << endl;
	}

};

int main(int argc, char *argv[]){
	// Error checking
	if(argc < 2){
		cerr << "usage: ./nums [-a] INTS_FILE_PATH\n";
		return EXIT_FAILURE;
	}
	
	if(argv[1] != "-a"){
		cerr << "Option can only be [-a]\n";
		return EXIT_FAILURE;
	}
	
	if(!in.good()){
		cerr << "cannot read " << argv[2] << ": No such file or directory\n";
	}
	
	using TestType = unsigned int;
	int i;
	// Create seq test type
	
}


