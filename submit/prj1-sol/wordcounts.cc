#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <vector>

// MAX_N_OUT: Positive int specifying the max # of words to be output
// MIN_WORD_LEN: Positive int specifying the minimum length of words to be output
// MAX_WORD_LEN: Positive integer specifying the maximum length of words to be output. *Must be >= MIN_WORD_LEN*
// FILE...: Name of file(s) which will be the source of word

typedef unsigned int Count;
typedef std::pair<std::string, Count> WordCount;

bool wordCountCompare(const WordCount &a, const WordCount &b){
	// if occurances are same return the word that is lexographically first
	if(a.second == b.second){
		return a.first < b.first;
	}
	else{
	       	return a.second > b.second;
	}
}
int main(int argc, char *argv[]){
	// Check for correct number of args
	if(argc < 4){
		std::cerr << "usage: MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE...\n";
		return EXIT_FAILURE;
	}

	// Convert args to ints
	int MAX_N_OUT = std::stoi(argv[1]);
	int MIN_WORD_LEN = std::stoi(argv[2]);
	int MAX_WORD_LEN = std::stoi(argv[3]);

	// Verify arguments are correct
	char *end1;
	char *end2;
	char *end3;
	int correct_input1 = strtol(argv[1], &end1, 10);
	int correct_input2 = strtol(argv[2], &end2, 10);
	int correct_input3 = strtol(argv[3], &end3, 10);

	if(*end1 != '\0'){
		std::cerr << "bad integer value \"" << argv[1] << "\" for MAX_N_OUT" << std::endl;
		return EXIT_FAILURE;
	}
	if(*end2 != '\0'){
		std::cerr << "bad integer value \"" << argv[2] << "\" for MIN_WORD_LEN" << std::endl;
		return EXIT_FAILURE;
	}
	if(*end3 != '\0'){
		std::cerr << "bad integer value \"" << argv[3] << "\" for MAX_WORD_LEN" << std::endl;
		return EXIT_FAILURE;
	}

	if(MAX_WORD_LEN < MIN_WORD_LEN){
		std::cerr << "MIN_WORD_LEN " << MIN_WORD_LEN << " is greater than MAX_WORD_LEN " << MAX_WORD_LEN << std::endl;
		return EXIT_FAILURE;
	}
		
	// Convert arg to readable file
	std::ifstream in(argv[4]);

	typedef unsigned int Count;
	// Create map to read words to
	std::unordered_map<std::string, Count> map;
	// Create map
	if(!in.good()){
		std::cerr << "cannot read " << argv[4] << ":" << std::endl;
		std::cerr << "\tno such file or directory" << std::endl;
		return EXIT_FAILURE;
	}
	
	while(in.good()){
		//std::cout << "here\n";
		std::string w;
		in >> w;
		//std::cout << w << std::endl;
		transform(w.begin(),w.end(),w.begin(), ::tolower);
		// remove nonalphabetic characters
		w.erase(remove_if(w.begin(),w.end(), [](char c) { return !isalpha(c); } ), w.end());
		// check if word meets requirements
		if((w.length() >= MIN_WORD_LEN) && (w.length() <= MAX_WORD_LEN)){
			if(map.count(w) == 0){
				Count &count = map[w];
				count +=1;
			}
			else{
				map[w]+=1;
			}
			}
	}
	
	auto wordCounts = std::vector<WordCount>(map.begin(), map.end());
	sort(wordCounts.begin(), wordCounts.end(), wordCountCompare);

	int output = MAX_N_OUT;
	if(MAX_N_OUT > map.size()){
		output = map.size();
	}
	
	for(int i = 0; i < output; i++){
		std::cout << wordCounts[i].first << ":  " << wordCounts[i].second << std::endl;
	}

	if(!in.eof()){
		std::cerr << "Error\n";
	}
	
}

