#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "01000111",
          .expected = 6,
      },
      {
          .s = "0011",
          .expected = 4,
      },
      {
          .s = "111",
          .expected = 0,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::findTheLongestBalancedSubstring(s);
    REQUIRE(expected == actual);
  }
}
