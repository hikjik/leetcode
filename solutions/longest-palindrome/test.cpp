#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abccccdd",
          .expected = 7,
      },
      {
          .s = "a",
          .expected = 1,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::longestPalindrome(s);
    REQUIRE(expected == actual);
  }
}
