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
      {
          .s = " ",
          .expected = 1,
      },
  };

  SECTION("Sliding Window") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = sliding_window::Solution::lengthOfLongestSubstring(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Hash Table") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = hash_table::Solution::lengthOfLongestSubstring(s);
      REQUIRE(expected == actual);
    }
  }
}
