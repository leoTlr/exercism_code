#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <string>
#include <vector>
#include <map>

namespace anagram {

    class anagram {
        std::string base_word_;
        std::map<char, size_t> word_map_;
        std::map<char, size_t> map_word(std::string const&) const;
    public:
        anagram(std::string const& base_word) : 
            base_word_(base_word), 
            word_map_(map_word(base_word))
        {};
        std::vector<std::string> matches(const std::vector<std::string> wordlist) const;
        bool is_anagram(std::string const& word) const;
    };
}  // namespace anagram

#endif // ANAGRAM_H