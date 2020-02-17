#include "food_chain.h"

#include <map>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <iostream>

using namespace std;

const vector<string> animal_order {
    "fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"
};

const map<string,string> end_senteces {
    {"fly", "I don't know why she swallowed the fly. Perhaps she'll die."},
    {"horse", "She's dead, of course!"}
};

const map<string,string> swallow_comments {
    {"bird", "How absurd to swallow a bird!"},
    {"cat", "Imagine that, to swallow a cat!"},
    {"dog", "What a hog, to swallow a dog!"},
    {"goat", "Just opened her throat and swallowed a goat!"},
    {"cow", "I don't know how she swallowed a cow!"},
};

string verse_start_sentence(string const& animal_name) {
    return "I know an old lady who swallowed a " + animal_name + ".";
}

string spiderify(string const& animal_name, bool catch_sentence = false) {
    if (animal_name != "spider" && !catch_sentence)
        return "";
    else if (animal_name != "spider" && catch_sentence)
        return animal_name;
    else if (animal_name == "spider" && catch_sentence)
        return animal_name + " that wriggled and jiggled and tickled inside her";
    else // spider and not catch_sentence -> second sentence
        return "It wriggled and jiggled and tickled inside her.";
}

string verse_swallow_comment(string const& animal_name) {
    try {
        return swallow_comments.at(animal_name);
    } catch (out_of_range&) {
        return spiderify(animal_name, false);
    }
}

string verse_end_sentece(string const& animal_name) {
    try {
        return end_senteces.at(animal_name);
    } catch (out_of_range&) {
        return end_senteces.at("fly");
    }
}

string catch_sentence(string const& animal_name, string const& previous_animal_name) {
    return "She swallowed the " + animal_name + " to catch the " + spiderify(previous_animal_name, true) + ".";
}

namespace food_chain {

    string verse(const size_t nr) {

        if (nr < 1 || nr > 8)
            throw invalid_argument("verse nr has to be from 1 to 8");
        
        auto _verse = stringstream{};

        auto animal_pos = nr - 1;
        auto animal = animal_order.at(animal_pos);

        _verse << verse_start_sentence(animal) << endl;

        if (nr != animal_order.size()) {

            auto swallow_comment = verse_swallow_comment(animal);
            if (!swallow_comment.empty())
                _verse << swallow_comment << endl;

            auto rev_it = animal_order.rbegin() + (animal_order.size() - nr);
            for (; rev_it < animal_order.rend() - 1; rev_it++) {
                animal = *rev_it;
                _verse << catch_sentence(animal, *std::next(rev_it, 1)) << endl;
            }   
        }
        _verse << verse_end_sentece(animal) << endl;

        return _verse.str();
    }

    string verses(const size_t from, const size_t to) {

        if (from < 1 || from > 8 || to < 1 || to > 8 || to < from )
            throw invalid_argument("invalid range");

        auto _verses = stringstream{};
        for (size_t i = from; i <= to; i++)
            _verses << verse(i) << endl;

        return _verses.str();
    }

    string sing() {
        return verses(1, 8);
    }
}  // namespace food_chain
