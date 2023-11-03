#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    std::string s3;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "aabcc",
          .s2 = "dbbca",
          .s3 = "aadbbcbcac",
          .expected = true,
      },
      {
          .s1 = "aabcc",
          .s2 = "dbbca",
          .s3 = "aadbbbaccc",
          .expected = false,
      },
      {
          .s1 = "",
          .s2 = "",
          .s3 = "",
          .expected = true,
      },
  };

  SECTION("Memoization") {
    for (const auto &[s1, s2, s3, expected] : test_cases) {
      const auto actual = memo::Solution::isInterleave(s1, s2, s3);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[s1, s2, s3, expected] : test_cases) {
      const auto actual = dp::Solution::isInterleave(s1, s2, s3);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memory Optimized") {
    for (const auto &[s1, s2, s3, expected] : test_cases) {
      const auto actual = optimized::Solution::isInterleave(s1, s2, s3);
      REQUIRE(expected == actual);
    }
  }
}
