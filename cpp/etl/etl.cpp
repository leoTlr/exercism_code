#include "etl.h"

#include <cctype>

using namespace std;

namespace etl {
    
    map<char, int> transform(map<int, std::vector<char>> old) {
        
        map<char, int> transformed {};
        
        // in c++17 one cluld do for (auto& [score, letters] : old)
        for (auto& kv_pair : old) {
            auto score = kv_pair.first;
            auto letters = kv_pair.second;
            for (char c : letters)
                transformed[tolower(c)] = score;
        }
        
        return transformed;
    }
}  // namespace etl
