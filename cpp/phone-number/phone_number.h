#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>
#include <stdexcept> //domain_error

namespace phone_number {

    class phone_number {
        std::string country_code_{2};
        std::string area_code_{3};
        std::string exchange_code_{3};
        std::string subscriber_nr_{4};
    public:
        phone_number(std::string const& number);
        std::string area_code(){return area_code_;};
        std::string number(){return area_code_ + exchange_code_ + subscriber_nr_;};
        operator std::string() const {
            return '(' + area_code_ + ") " + exchange_code_ + '-' + subscriber_nr_;
        }
    };

}  // namespace phone_number

#endif // PHONE_NUMBER_H