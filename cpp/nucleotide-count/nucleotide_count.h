#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>

namespace nucleotide_count {

    // dint use size_t cause i would need to implement operator== for map<char,int> for tests to compile

    class counter {
        std::map<char, int> counts_ {
            {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0}
        };
    public:
        counter(std::string const& nucleotides);
        std::map<char, int> nucleotide_counts() const {return counts_;};
        int count(const char nucleotid) const {
            try {
                return counts_.at(nucleotid);
            } catch (std::out_of_range&){
                throw std::invalid_argument("Bad nucleotid: " + nucleotid);
            }
        }
    };
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H