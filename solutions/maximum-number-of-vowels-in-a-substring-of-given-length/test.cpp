#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abciiidef",
          .k = 3,
          .expected = 3,
      },
      {
          .s = "aeiou",
          .k = 2,
          .expected = 2,
      },
      {
          .s = "leetcode",
          .k = 3,
          .expected = 2,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::maxVowels(s, k);
    REQUIRE(expected == actual);
  }
}
