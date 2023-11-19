#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s1;
    std::string s2;
    std::string s3;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s1 = "abc",
          .s2 = "abb",
          .s3 = "ab",
          .expected = 2,
      },
      {
          .s1 = "dac",
          .s2 = "bac",
          .s3 = "cac",
          .expected = -1,
      },
  };

  for (const auto &[s1, s2, s3, expected] : test_cases) {
    const auto actual = Solution::findMinimumOperations(s1, s2, s3);
    REQUIRE(expected == actual);
  }
}
