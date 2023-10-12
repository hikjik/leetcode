#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abab",
          .expected = true,
      },
      {
          .s = "aba",
          .expected = false,
      },
      {
          .s = "abcabcabcabc",
          .expected = true,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::repeatedSubstringPattern(s);
    REQUIRE(expected == actual);
  }
}
