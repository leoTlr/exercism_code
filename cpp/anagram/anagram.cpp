#include "anagram.h"

#include <cctype>
#include <algorithm>

using namespace std;

namespace anagram {

    map<char, size_t> anagram::map_word(string const& word) const {
        map<char, size_t> charmap;
        for (char c : word)
            if (isalpha(c))
                charmap[tolower(c)]++; // missing keys will be created and its values default initialized
        return charmap;
    }

    bool iequals(string const& a, string const& b) {
        // caseless comparison
        return equal(
            a.begin(), a.end(),
            b.begin(), b.end(), 
            [](char a, char b){ return tolower(a) == tolower(b); }
        );
    }

    bool anagram::is_anagram(string const& word) const {
        if (word.length() != base_word_.length() || iequals(word, base_word_))
            return false;
        return word_map_ == map_word(word);
    }

    vector<string> anagram::matches(vector<string> wordlist) const {
        vector<string> matches_list;
        for (auto& word : wordlist)
            if (is_anagram(word))
                matches_list.push_back(word);
        return matches_list;
    } 
}  // namespace anagram
