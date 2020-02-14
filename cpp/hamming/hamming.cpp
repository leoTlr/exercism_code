#include "hamming.h"

#include <stdexcept>

namespace hamming {

    size_t compute(const std::string strand_a, const std::string strand_b) {
        if (strand_a.length() != strand_b.length())
            throw std::domain_error("unequal lengths");
        
        size_t count = 0;
        for (size_t pos=0; pos < strand_a.length(); pos++)
            if (strand_a[pos] != strand_b[pos])
                count++;
                
        return count;
    }

}  // namespace hamming
