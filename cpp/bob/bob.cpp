#include "bob.h"

#include <cctype>
#include <algorithm>

namespace bob {
    
    bool is_question(std::string const& sentence){
        auto pos = sentence.rbegin();
        while (isspace(*pos))
            pos++; // edge cases like "bla?   "
        return *pos == '?';
    }

    bool is_yelled(std::string const& sentence){
        bool contains_letter = false; // edge cases like "4"
        for (char c : sentence) {
            if (isalpha(c)) {
                contains_letter = true;
                if (islower(c))
                    return false;
            }
        }
        return true ? contains_letter : false;
    }

    bool is_all_space(std::string const& sentence){
        return std::all_of(sentence.begin(), sentence.end(), [](char c){return isspace(c);});
    }

    std::string hey(std::string sentence) {

        bool question = is_question(sentence);
        bool yelled = is_yelled(sentence);

        if (is_all_space(sentence))
            return "Fine. Be that way!";

        if (question) {
            if (yelled)
                return "Calm down, I know what I'm doing!";
            return "Sure.";
        } 
        else if (yelled)
            return "Whoa, chill out!";

        return "Whatever.";
    }
}  // namespace bob
