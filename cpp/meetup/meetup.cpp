#include "meetup.h"

using namespace std;
using namespace boost::gregorian;

namespace meetup {

    date scheduler::teenth(greg_weekday weekday) const {
        auto fdaf = first_day_of_the_week_after{weekday};
        return  fdaf.get_date(date{base_year_, base_month_, 12});
    }

    date scheduler::nth_weekday(boost::gregorian::nth_kday_of_month::week_num n, greg_weekday weekday) const {
        auto ndow = nth_day_of_the_week_in_month{n, weekday, base_month_};
        return ndow.get_date(base_year_);
    }

}  // namespace meetup
