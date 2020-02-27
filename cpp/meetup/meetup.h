#if !defined(MEETUP_H)
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

    class scheduler {

        boost::date_time::months_of_year base_month_;
        size_t base_year_;
        boost::gregorian::date teenth(boost::gregorian::greg_weekday weekday) const;
        boost::gregorian::date nth_weekday(boost::gregorian::nth_kday_of_month::week_num n, boost::gregorian::greg_weekday weekday) const;
        
      public:
        scheduler(boost::date_time::months_of_year month, size_t year) :
            base_month_(month), base_year_(year){};

        using wd = boost::gregorian::greg_weekday::weekday_enum;
        using dow = boost::gregorian::nth_kday_of_month::week_num;
        boost::gregorian::date monteenth() const {return teenth(wd::Monday);};
        boost::gregorian::date tuesteenth() const {return teenth(wd::Tuesday);};
        boost::gregorian::date wednesteenth() const {return teenth(wd::Wednesday);};
        boost::gregorian::date thursteenth() const {return teenth(wd::Thursday);};
        boost::gregorian::date friteenth() const {return teenth(wd::Friday);};
        boost::gregorian::date saturteenth() const {return teenth(wd::Saturday);};
        boost::gregorian::date sunteenth() const {return teenth(wd::Sunday);};
        boost::gregorian::date first_monday() const {return nth_weekday(dow::first, wd::Monday);};
        boost::gregorian::date first_tuesday() const {return nth_weekday(dow::first, wd::Tuesday);};
        // ...
        boost::gregorian::date third_wednesday() const {return nth_weekday(dow::third, wd::Wednesday);};
        // ... sick of writing more boilerplate

    };

}  // namespace meetup

#endif // MEETUP_H