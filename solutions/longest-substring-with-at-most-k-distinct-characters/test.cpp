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
          .s = "eceba",
          .k = 2,
          .expected = 3,
      },
      {
          .s = "aa",
          .k = 1,
          .expected = 2,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::lengthOfLongestSubstringKDistinct(s, k);
    REQUIRE(expected == actual);
  }
}
