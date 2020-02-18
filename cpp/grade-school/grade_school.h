#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <string>
#include <vector>
#include <map>

namespace grade_school {

    class school {
        std::map<int, std::vector<std::string>> roster_{};
    public:
        void add(std::string const& name, const int grade);
        std::map<int, std::vector<std::string>> roster() const {return roster_;};
        std::vector<std::string> grade(const int grade) const;
    };

}  // namespace grade_school

#endif // GRADE_SCHOOL_H