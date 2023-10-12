#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "III",
          .expected = 3,
      },
      {
          .s = "LVIII",
          .expected = 58,
      },
      {
          .s = "MCMXCIV",
          .expected = 1994,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::romanToInt(s);
    REQUIRE(expected == actual);
  }
}
