#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

#include <cstddef> // size_t

/*
    Mercury: orbital period 0.2408467 Earth years
    Venus: orbital period 0.61519726 Earth years
    Earth: orbital period 1.0 Earth years, 365.25 Earth days, or 31557600 seconds
    Mars: orbital period 1.8808158 Earth years
    Jupiter: orbital period 11.862615 Earth years
    Saturn: orbital period 29.447498 Earth years
    Uranus: orbital period 84.016846 Earth years
    Neptune: orbital period 164.79132 Earth years
*/

namespace space_age {

    class space_age {
        size_t age_seconds_;
        const size_t seconds_per_earth_year_ = 31557600;
        double planet_age(double factor = 1.0) const {
            return (age_seconds_) / (seconds_per_earth_year_ * factor);
        }
      public: 
        space_age(const size_t seconds) : age_seconds_(seconds) {};
        double seconds() const {return age_seconds_;};
        double on_mercury() const {return planet_age(0.2408467);};
        double on_venus() const {return planet_age(0.61519726);};
        double on_earth() const {return planet_age();};
        double on_mars() const {return planet_age(1.8808158);};
        double on_jupiter() const {return planet_age(11.862615);};
        double on_saturn() const {return planet_age(29.447498);};
        double on_uranus() const {return planet_age(84.016846);};
        double on_neptune() const {return planet_age(164.79132);};
    };

}  // namespace space_age

#endif // SPACE_AGE_H