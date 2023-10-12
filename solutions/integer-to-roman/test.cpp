#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int num;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .num = 3,
          .expected = "III",
      },
      {
          .num = 58,
          .expected = "LVIII",
      },
      {
          .num = 1994,
          .expected = "MCMXCIV",
      },
  };

  for (const auto &[num, expected] : test_cases) {
    const auto actual = Solution::intToRoman(num);
    REQUIRE(expected == actual);
  }
}
