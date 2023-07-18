#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::string> req_skills{"java", "nodejs", "reactjs"};
    std::vector<std::vector<std::string>> people{
        {"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
    std::vector<int> expected{0, 2};
    REQUIRE(expected == Solution::smallestSufficientTeam(req_skills, people));
  }
  {
    std::vector<std::string> req_skills{"algorithms", "math",   "java",
                                        "reactjs",    "csharp", "aws"};
    std::vector<std::vector<std::string>> people{
        {"algorithms", "math", "java"},
        {"algorithms", "math", "reactjs"},
        {"java", "csharp", "aws"},
        {"reactjs", "csharp"},
        {"csharp", "math"},
        {"aws", "java"}};
    std::vector<int> expected{1, 2};
    REQUIRE(expected == Solution::smallestSufficientTeam(req_skills, people));
  }
  {
    std::vector<std::string> req_skills{"mwobudvo", "goczubcwnfze", "yspbsez",
                                        "pf",       "ey",           "hkq"};
    std::vector<std::vector<std::string>> people{{},
                                                 {"mwobudvo"},
                                                 {"hkq"},
                                                 {"pf"},
                                                 {"pf"},
                                                 {"mwobudvo", "pf"},
                                                 {},
                                                 {"yspbsez"},
                                                 {},
                                                 {"hkq"},
                                                 {},
                                                 {},
                                                 {"goczubcwnfze", "pf", "hkq"},
                                                 {"goczubcwnfze"},
                                                 {"hkq"},
                                                 {"mwobudvo"},
                                                 {},
                                                 {"mwobudvo", "pf"},
                                                 {"pf", "ey"},
                                                 {"mwobudvo"},
                                                 {"hkq"},
                                                 {},
                                                 {"pf"},
                                                 {"mwobudvo", "yspbsez"},
                                                 {"mwobudvo", "goczubcwnfze"},
                                                 {"goczubcwnfze", "pf"},
                                                 {"goczubcwnfze"},
                                                 {"goczubcwnfze"},
                                                 {"mwobudvo"},
                                                 {"mwobudvo", "goczubcwnfze"},
                                                 {},
                                                 {"goczubcwnfze"},
                                                 {},
                                                 {"goczubcwnfze"},
                                                 {"mwobudvo"},
                                                 {},
                                                 {"hkq"},
                                                 {"yspbsez"},
                                                 {"mwobudvo"},
                                                 {"goczubcwnfze", "ey"}};
    std::vector<int> expected{12, 18, 23};
    REQUIRE(expected == Solution::smallestSufficientTeam(req_skills, people));
  }
}
