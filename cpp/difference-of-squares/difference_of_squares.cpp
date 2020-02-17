#include "difference_of_squares.h"

#include <cmath>

using namespace std;

namespace difference_of_squares {

    size_t square_of_sum(size_t n) {
        size_t sum = 0;
        for (size_t i=1; i<n+1; i++)
            sum += i;
        return  pow(sum, 2);
    }
    size_t sum_of_squares(size_t n) {
        size_t sum = 0;
        for (size_t i=1; i<n+1; i++)
            sum += pow(i, 2);
        return sum;
    }
    size_t difference(size_t n) {
        size_t _sum_of_squares = sum_of_squares(n);
        size_t _square_of_sum = square_of_sum(n);
        return _square_of_sum - _sum_of_squares;
    }

}  // namespace difference_of_squares
