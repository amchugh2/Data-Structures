#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>

// MAX_N_OUT: Positive int specifying the max # of words to be output
// MIN_WORD_LEN: Positive int specifying the minimum length of words to be output
// MAX_WORD_LEN: Positive integer specifying the maximum length of words to be output. *Must be >= MIN_WORD_LEN*
// FILE...: Name of file(s) which will be the source of word

int main(int argc, char *argv[]){
	// Check for correct number of args
	/*
	if(argc < 4){
		std::cerr << "usage: MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE...";
		return EXIT_FAILURE;
	}
	// Convert args to ints
	int MAX_N_OUT = std::stoi(argv[0]);
	int MIN_WORD_LEN = std::stoi(argv[1]);
	int MAX_WORD_LEN = std::stoi(argv[2]);

	// Verify args are ints
	if((!isdigit(MAX_N_OUT)) || (!isdigit(MIN_WORD_LEN)) || (!isdigit(MAX_WORD_LEN))){
		std::cerr << "Invalid entry. Please enter Integer values for MAX_N_OUT, MIN_WORD_LEN, MAX_WORD_LEN";
	}	
	
	// Verify arguments are correct
	if((MAX_N_OUT <= 0) |(MIN_WORD_LEN <=0) |(MAX_WORD_LEN <=0) |( MAX_WORD_LEN <= MIN_WORD_LEN)){
		std::cerr << "Invalid entry. Please enter MAX_N_OUT, MIN_WORD_LEN, MAX_WORD_LEN > 0 and MAX_WORD_LEN greater than MIN_WORD_LEN";
	}
	*/
	// Convert arg to readable file
	// String must be: lowercase and stripped of all ' chars
	std::ifstream in("test.txt");
	while(in.good()){
		std::string w;
		in >> w;
		/*
		for(char &c: w){
			c = std::tolower(c);
		}*/
		std::cout << w << std::endl;
	}
	if(!in.eof()){
		std::cerr << "Error\n";
	}
	
}

