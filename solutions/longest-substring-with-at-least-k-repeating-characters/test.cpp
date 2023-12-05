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
          .s = "aaabb",
          .k = 3,
          .expected = 3,
      },
      {
          .s = "ababbc",
          .k = 2,
          .expected = 5,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::longestSubstring(s, k);
    REQUIRE(expected == actual);
  }
}
