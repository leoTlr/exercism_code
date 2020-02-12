#include "isogram.h"

#include <map>

namespace isogram {

	// creating a set and comparing its size with input str does not work for edge cases like "a-b-c" or "aA"
	
	bool is_isogram(std::string str) {

		// access with operator[] and non-existent key will create key and default initialize value
		std::map<char,size_t> counter;

		for (char c : str) {
			if (isspace(c) || c == '-') // edge cases
				continue;
			else if (++counter[std::tolower(c)] > 1) // count lowercase only
				return false;
		}
		return true;
	}
}  // namespace isogram
