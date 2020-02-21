#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>
#include <unordered_set>
#include <random>
#include <chrono>
#include <memory>

class RandomCharGenerator {
    
    std::string charpool_;
    std::shared_ptr<std::mt19937_64> prng_; // all instances share same prng
    std::uniform_int_distribution<size_t> distribution_;

  public:
    RandomCharGenerator(std::string const& charpool, std::shared_ptr<std::mt19937_64> prng);
    char operator()(); // pick char of charpool at random index
};

class NameGenerator {

    std::mt19937_64 prng_; // mersenne twister (not cryptographically secure)
    std::vector<std::pair<RandomCharGenerator, size_t>> generator_sequence_; // two rand upper letters, three rand digits
    std::unordered_set<std::string> generated_names_;
    size_t name_len_ = 0;

  public:
    NameGenerator(size_t seed = std::chrono::system_clock::now().time_since_epoch().count());
    std::string generate();
    bool remove(std::string const& name);
};

namespace robot_name {

    class robot {

        NameGenerator name_generator_;
        std::string name_;

      public:
        robot();
        std::string name() const {return name_;};
        void reset();
    };

}  // namespace robot_name

#endif // ROBOT_NAME_H