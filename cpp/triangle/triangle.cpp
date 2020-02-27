#include "triangle.h"

#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

namespace triangle {

    bool violates_inequality_rule(size_t a, size_t b, size_t c) {
        vector<size_t> permutation {a, b, c};

        do {
            if (!(permutation[0] <= permutation[1] + permutation[2]))
                return true;
        } while (next_permutation(permutation.begin(), permutation.end()));

        return false;
    }

    flavor kind(size_t a, size_t b, size_t c) {
        
        if (violates_inequality_rule(a, b, c))
            throw domain_error("triangle inequality rule violation");

        if (a == b && b == c) {
            if (a == 0)
                throw std::domain_error("illegal size");
            return flavor::equilateral;
        }
        else if (a == b || b == c || a == c)
            return flavor::isosceles;

        else return flavor::scalene;
    }

}  // namespace triangle
