#include "phone_number.h"

#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

namespace phone_number {

    // (countrycde) (NXX)-NXX-XXXX // n := [2,9]; x := [0,9] // "-. ()" -> valid separators
    // challenge assumption is that only (optional) country code 1 is valid
    // this wont work with two-digit country codes
    phone_number::phone_number(string const& number) {

        string parsed{};

        copy_if( // keep digits only
            number.begin(), number.end(), back_inserter(parsed), 
            [](char c){
                return static_cast<bool>(isdigit(static_cast<int>(c)));
            }
        );
        
        if (parsed.length() == 10)
            country_code_ = "1";
        else if  (parsed.length() == 11 && parsed[0] == '1') 
            country_code_ = parsed.substr(1);
        else
            throw domain_error("invalid format");

        area_code_ = parsed.length() == 10 ? parsed.substr(0,3) : parsed.substr(1,3);
        if (area_code_[0] == '0' || area_code_[0] == '1')
            throw domain_error("invalid area code");

        exchange_code_ = parsed.length() == 10 ? parsed.substr(3,3) : parsed.substr(4,3);
        if (exchange_code_[0] == '0' || exchange_code_[0] == '1')
            throw domain_error("invalid exchange code");

        subscriber_nr_ = parsed.length() == 10 ? parsed.substr(6) : parsed.substr(7);

    }
}  // namespace phone_number
