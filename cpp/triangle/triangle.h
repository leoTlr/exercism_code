#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <cstddef>

namespace triangle {
    
    enum flavor {
        equilateral,
        isosceles,
        scalene
    };

    /*
        note the param types are size_t, so the test with float values
        will fail (won't even compile then)

        size_t is perfect for an otherwise unspecified length unit.
        Accepting float values would be bad design.

        all other test cases work perfectly fine

        (the test case with negative number will wrap around into a 
        positive big number but it will fail on the triangle inequality
        rule check and throw an error then -> intended behavior since the 
        caller is in charge of actually providing an unsigned value)
    */
    flavor kind(size_t a, size_t b, size_t c);

}  // namespace triangle

#endif // TRIANGLE_H