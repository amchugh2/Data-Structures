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
	return (a.second < b.second);
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
	

	// Verify args are ints
	if((!isdigit(MAX_N_OUT)) || (!isdigit(MIN_WORD_LEN)) || (!isdigit(MAX_WORD_LEN))){
		std::cerr << "Invalid entry. Please enter Integer values for MAX_N_OUT, MIN_WORD_LEN, MAX_WORD_LEN\n";
	}	
	
	// Verify arguments are correct
	if((MAX_N_OUT <= 0) |(MIN_WORD_LEN <=0) |(MAX_WORD_LEN <=0) |( MAX_WORD_LEN <= MIN_WORD_LEN)){
		std::cerr << "Invalid entry. Please enter MAX_N_OUT, MIN_WORD_LEN, MAX_WORD_LEN > 0 and MAX_WORD_LEN greater than MIN_WORD_LEN\n";
	}
	
	// Convert arg to readable file
	std::ifstream in("test.txt");

	typedef unsigned int Count;
	// Create map to read words to
	std::unordered_map<std::string, Count> map;

	// Create map

	while(in.good()){
		std::string w;
		in >> w;
		// make word lowercase
		transform(w.begin(),w.end(),w.begin(), ::tolower);
		// remove nonalphabetic characters
		w.erase(remove_if(w.begin(),w.end(), [](char c) { return !isalpha(c); } ), w.end());

		// check if word meets requirements
		if((w.length() >= MIN_WORD_LEN) && (w.length() <= MAX_WORD_LEN)){
			Count& count = map[w];
			count += 1;
		}
	}
	
	//typedef std::pair<std::string, Count> wordCount;
	auto wordCounts = std::vector<WordCount>(map.begin(), map.end());
	sort(wordCounts.begin(), wordCounts.end(), wordCountCompare);

	// Print up to N_WORDS_OUT
	for(int i = 0; i >= MAX_N_OUT; i++){
		std::cout << wordCounts[i].first << ": " << wordCounts[i].second << std::endl;
	}

	if(!in.eof()){
		std::cerr << "Error\n";
	}
	
}

