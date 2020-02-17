#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H

#include <string>
#include <cstddef>

namespace food_chain {
    std::string verse(const size_t from);
    std::string verses(const size_t from, const size_t to);
    std::string sing();
}  // namespace food_chain

#endif // FOOD_CHAIN_H