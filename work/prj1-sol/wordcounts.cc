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
		return a.first > a.first;
	}
	// normal
	else return a.second > b.second;
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
	if((isdigit(MAX_N_OUT) != 0) || (isdigit(MIN_WORD_LEN) != 0) || (isdigit(MAX_WORD_LEN) != 0)){
		std::cerr << "Invalid entry. Please enter Integer values for MAX_N_OUT, MIN_WORD_LEN, MAX_WORD_LEN\n";
	return -1;
	}	
	
	// Verify arguments are correct
	if((MAX_N_OUT <= 0) |(MIN_WORD_LEN <=0) |(MAX_WORD_LEN <=0) |( MAX_WORD_LEN <= MIN_WORD_LEN)){
		std::cerr << "Invalid entry. Please enter MAX_N_OUT, MIN_WORD_LEN, MAX_WORD_LEN > 0 and MAX_WORD_LEN greater than MIN_WORD_LEN\n";
	return -1;
	}
	
	// Convert arg to readable file
	std::ifstream in(argv[4]);

	typedef unsigned int Count;
	// Create map to read words to
	std::unordered_map<std::string, Count> map;

	// Create map
	while(in.good()){
		//std::cout << "here\n";
		std::string w;
		in >> w;
		//std::cout << w << std::endl;
		transform(w.begin(),w.end(),w.begin(), ::tolower);
		// remove nonalphabetic characters
		w.erase(remove_if(w.begin(),w.end(), [](char c) { return !isalpha(c); } ), w.end());
		//std::cout << "here 3\n";
		// check if word meets requirements
		if((w.length() >= MIN_WORD_LEN) && (w.length() <= MAX_WORD_LEN)){
			if(map.count(w) == 0){
				//std::cout << map[w] << std::endl;	
				Count &count = map[w];
				count +=1;
			}
			else{
				//std::cout << "before increment:" << map[w] << std::endl;
				map[w]+=1;
				//std::cout << "after increment: " << map[w] << std::endl;
			}
		}

	}
	
	auto wordCounts = std::vector<WordCount>(map.begin(), map.end());
	sort(wordCounts.begin(), wordCounts.end(), wordCountCompare);
	
	if(map.size() < MAX_N_OUT){
		std::cerr << "Please enter a MAX_N_OUT that is smaller than the number of different words in the text file" << std::endl;
	return -1;
	}
	for(int j = 0; j < MAX_N_OUT; j++){
		std::cout << wordCounts[j].first << ": " << wordCounts[j].second << std::endl;
	}
	//std::cout << "end of for loop" << std::endl;

	if(!in.eof()){
		std::cerr << "Error\n";
	}
	
}

