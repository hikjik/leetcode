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
          .s = "aabbc",
          .k = 3,
          .expected = 0,
      },
      {
          .s = "abc",
          .k = 2,
          .expected = 1,
      },
      {
          .s = "leetcode",
          .k = 8,
          .expected = 0,
      },
  };

  SECTION("Memoization") {
    for (const auto &[s, k, expected] : test_cases) {
      const auto actual = memo::Solution::palindromePartition(s, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s, k, expected] : test_cases) {
      const auto actual = dp::Solution::palindromePartition(s, k);
      REQUIRE(expected == actual);
    }
  }
}
