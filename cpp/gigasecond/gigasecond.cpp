#include "gigasecond.h"

#include <cmath>

using namespace boost::posix_time;

namespace gigasecond {
    ptime advance(ptime timepoint) {
        return timepoint + seconds(static_cast<unsigned int>(pow(10, 9)));
    }
}  // namespace gigasecond
