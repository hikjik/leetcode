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

  for (const auto &[s1, s2, s3, expected] : test_cases) {
    const auto actual = Solution::isInterleave(s1, s2, s3);
    REQUIRE(expected == actual);
  }
}
