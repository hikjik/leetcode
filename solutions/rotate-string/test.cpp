#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string goal;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcde",
          .goal = "cdeab",
          .expected = true,
      },
      {
          .s = "abcde",
          .goal = "abced",
          .expected = false,
      },
      {
          .s = "aa",
          .goal = "a",
          .expected = false,
      },
  };

  for (const auto &[s, goal, expected] : test_cases) {
    const auto actual = Solution::rotateString(s, goal);
    REQUIRE(expected == actual);
  }
}
