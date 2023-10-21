#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "aba",
          .expected = true,
      },
      {
          .s = "abc",
          .expected = false,
      },
      {
          .s = "abca",
          .expected = true,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::validPalindrome(s);
    REQUIRE(expected == actual);
  }
}
