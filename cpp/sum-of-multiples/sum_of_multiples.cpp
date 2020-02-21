#include "sum_of_multiples.h"

#include <functional>
#include <numeric>
#include <unordered_set>

using namespace std;

namespace sum_of_multiples {

    size_t to (vector<size_t> const& basenums, const size_t n) {

        unordered_set<size_t> multiples;
        multiples.reserve(n*5);
        
        for (auto& num : basenums) {
            size_t i = 0, mult = 0;
            while ((mult = i*num) < n) {
                multiples.emplace(mult);
                i++;
            }
        }
            
        return accumulate(multiples.begin(), multiples.end(), 0, plus<size_t>());
    }
}  // namespace sum_of_multiples
