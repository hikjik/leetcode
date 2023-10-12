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
          .s = "acfgbd",
          .k = 2,
          .expected = 4,
      },
      {
          .s = "abcd",
          .k = 3,
          .expected = 4,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::longestIdealString(s, k);
    REQUIRE(expected == actual);
  }
}
