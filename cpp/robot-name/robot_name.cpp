#include "robot_name.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

RandomCharGenerator::RandomCharGenerator(string const& charpool, shared_ptr<mt19937_64> prng) : 
    charpool_(charpool),
    prng_{prng} 
{
    if (charpool_.length() < 1)
        throw invalid_argument("empty charpool");
    distribution_ = std::uniform_int_distribution<size_t> {0, charpool_.length()-1};
}

char RandomCharGenerator::operator()() {
    return charpool_.at(distribution_(*prng_));
}

NameGenerator::NameGenerator(size_t seed) : prng_(mt19937_64 {seed}) {

    const std::string ascii_upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::string ascii_digits {"0123456789"};
    const size_t nr_letters = 2;
    const size_t nr_digits = 3;
    
    // all generators use same prng
    auto prng_ptr = make_shared<mt19937_64>(prng_);
    generator_sequence_.push_back({RandomCharGenerator{ascii_upper, prng_ptr}, nr_letters});
    generator_sequence_.push_back({RandomCharGenerator{ascii_digits, prng_ptr}, nr_digits});

    name_len_ = nr_digits + nr_letters;
}

string NameGenerator::generate() {

    string name;
    name.reserve(name_len_);

    do {
        name.clear();

        // with c++17 one could do: for (auto& [gen, n] : generator_sequence_)
        for (auto& _ : generator_sequence_) {
            auto gen = _.first;
            auto n = _.second;
            generate_n(back_inserter(name), n, gen);
        }
    } while (!generated_names_.emplace(name).second); // prevent duplicates

    return name;
}

namespace robot_name {

    robot::robot() : 
        name_generator_(NameGenerator{}), 
        name_(name_generator_.generate())
    {}

    void robot::reset() {
        name_ = name_generator_.generate();
    }

}  // namespace robot_name
