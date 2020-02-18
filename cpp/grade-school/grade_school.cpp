#include "grade_school.h"

#include <stdexcept>
#include <algorithm>

#include <iostream>

using namespace std;

namespace grade_school {

    void school::add(string const& name, const int grade) {
        roster_[grade].push_back(name);
        sort(roster_[grade].begin(), roster_[grade].end());
    }

    vector<string> school::grade(const int grade) const {
        try {
            return roster_.at(grade);
        } catch (out_of_range&) {
            return vector<string>{};
        }
    }

}  // namespace grade_school
