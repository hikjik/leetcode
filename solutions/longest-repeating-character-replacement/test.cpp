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
          .s = "ABAB",
          .k = 2,
          .expected = 4,
      },
      {
          .s = "AABABBA",
          .k = 1,
          .expected = 4,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::characterReplacement(s, k);
    REQUIRE(expected == actual);
  }
}
