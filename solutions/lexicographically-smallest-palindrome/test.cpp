#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "egcfe",
          .expected = "efcfe",
      },
      {
          .s = "abcd",
          .expected = "abba",
      },
      {
          .s = "seven",
          .expected = "neven",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::makeSmallestPalindrome(s);
    REQUIRE(expected == actual);
  }
}
