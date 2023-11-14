#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aabca",
          .expected = 3,
      },
      {
          .s = "adc",
          .expected = 0,
      },
      {
          .s = "bbcbaba",
          .expected = 4,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::countPalindromicSubsequence(s);
    REQUIRE(expected == actual);
  }
}
