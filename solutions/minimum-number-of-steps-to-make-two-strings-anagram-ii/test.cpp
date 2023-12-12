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
          .s = "leetcode",
          .t = "coats",
          .expected = 7,
      },
      {
          .s = "night",
          .t = "thing",
          .expected = 0,
      },
  };

  for (const auto &[s, t, expected] : test_cases) {
    const auto actual = Solution::minSteps(s, t);
    REQUIRE(expected == actual);
  }
}
