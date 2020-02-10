#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>

// MAX_N_OUT: Positive int specifying the max # of words to be output
// MIN_WORD_LEN: Positive int specifying the minimum length of words to be output
// MAX_WORD_LEN: Positive integer specifying the maximum length of words to be output. *Must be >= MIN_WORD_LEN*
// FILE...: Name of file(s) which will be the source of words


// Word: All non-alphabetic characters are removed
// 	 All upper-class characters are replaced by lower-case equivs

// Process:
// 1. Check for correct number of args
// 2. Open file and convert to C++ std::vector<std::string> using an interaor over the argv[] array:
// 	auto args = std::vector<std::string>(&argv[0], &argv[argc]);
// 3. Verify that MAX_N_OUT, MIN_WORD_LEN, MAX_WORD_LEN are correct
// 	Convert from std::string arg -> int using std::stoi(arg, endIndex) and verify that endIndex == arg.length() to ensure arg is int
// 4. Take each word and transform it to meet requirements
// 5. If transofmred word meets length requirement, enter it in to a map
// 	(need to check if already there)
// 	std::unordered_map<std::string, Count> map;
// 	...
// 	Count & count = map[transformedWord];
// 	count +=1;
// 	** Count is a suitable integral typedef
// 6. Sort entries in the map
// 	- Extract key-value pairs from the map into a vector using:
// 		typedef std::pair<std::string, Count> wordCount;
// 		auto wordCounts =
// 			std::vector<WordCount>(map.begin(), map.end());
// 	- Which now can be sorted using
// 		sort(wordCounts.begin(), wordCounts.end(), wordCountCompare()
// 7. Create wordCountCompare(): Comparison function which returns TRUE if two wordCount args meet ordering specified for project
int main(int argc, char *argv[]){
	// Check for correct number of args
	if(argc < 4){
		std::cerr << "usage: MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE...";
		return EXIT_FAILURE;
	}

	// Get file
	static const char *file = "FIXME";

	// Store word and count using map
	map<string, unsigned int> word_count;

	// Read from file
	



