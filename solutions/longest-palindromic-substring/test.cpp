#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    std::string expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "babad",
          .expected = "bab",
      },
      {
          .s = "cbbd",
          .expected = "bb",
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::longestPalindrome(s);
    REQUIRE(expected == actual);
  }
}
