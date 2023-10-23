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
          .s = "iiii",
          .k = 1,
          .expected = 36,
      },
      {
          .s = "leetcode",
          .k = 2,
          .expected = 6,
      },
      {
          .s = "zbax",
          .k = 2,
          .expected = 8,
      },
  };

  for (const auto &[s, k, expected] : test_cases) {
    const auto actual = Solution::getLucky(s, k);
    REQUIRE(expected == actual);
  }
}
