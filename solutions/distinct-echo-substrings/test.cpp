#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "abcabcabc",
          .expected = 3,
      },
      {
          .s = "leetcodeleetcode",
          .expected = 2,
      },
  };

  SECTION("DP") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = lcs::Solution::distinctEchoSubstrings(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Sliding Window") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = sliding_window::Solution::distinctEchoSubstrings(s);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Sliding Window + Rolling Hash") {
    for (const auto &[s, expected] : test_cases) {
      const auto actual = hash::Solution::distinctEchoSubstrings(s);
      REQUIRE(expected == actual);
    }
  }
}
