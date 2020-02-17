#include "nucleotide_count.h"

#include <cctype>
#include <stdexcept>

using namespace std;

namespace nucleotide_count {

    counter::counter(string const& nucleotides) {
        for (char c : nucleotides) {
            if (!(isalpha(c)))
                throw invalid_argument("Bad char: "+c);
            else if (! (c=='A' || c=='C' || c=='G' || c=='T'))
                throw invalid_argument("Bad char: "+c);
            counts_[c]++;
        }
    }
}  // namespace nucleotide_count
