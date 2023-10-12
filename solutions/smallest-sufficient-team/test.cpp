#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::string> req_skills;
    std::vector<std::vector<std::string>> people;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .req_skills{"java", "nodejs", "reactjs"},
          .people{{"java"}, {"nodejs"}, {"nodejs", "reactjs"}},
          .expected{0, 2},
      },
      {
          .req_skills{"algorithms", "math", "java", "reactjs", "csharp", "aws"},
          .people{{"algorithms", "math", "java"},
                  {"algorithms", "math", "reactjs"},
                  {"java", "csharp", "aws"},
                  {"reactjs", "csharp"},
                  {"csharp", "math"},
                  {"aws", "java"}},
          .expected{1, 2},
      },
  };

  for (const auto &[req_skills, people, expected] : test_cases) {
    const auto actual = Solution::smallestSufficientTeam(req_skills, people);
    REQUIRE(expected == actual);
  }
}
