#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcabcbb",
          .expected = 3,
      },
      {
          .s = "bbbbb",
          .expected = 1,
      },
      {
          .s = "pwwkew",
          .expected = 3,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::lengthOfLongestSubstring(s);
    REQUIRE(expected == actual);
  }
}
