#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string t;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "bab",
          .t = "aba",
          .expected = 1,
      },
      {
          .s = "leetcode",
          .t = "practice",
          .expected = 5,
      },
      {
          .s = "anagram",
          .t = "mangaar",
          .expected = 0,
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::minSteps(s, t);
    REQUIRE(expected == actual);
  }
}
