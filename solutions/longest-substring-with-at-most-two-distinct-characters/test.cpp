#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "eceba",
          .expected = 3,
      },
      {
          .s = "ccaabbb",
          .expected = 5,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::lengthOfLongestSubstringTwoDistinct(s);
    REQUIRE(expected == actual);
  }
}
