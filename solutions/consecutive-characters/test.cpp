#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::string s;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .s = "leetcode",
          .expected = 2,
      },
      {
          .s = "abbcccddddeeeeedcba",
          .expected = 5,
      },
  };

  for (const auto &[s, expected] : test_cases) {
    const auto actual = Solution::maxPower(s);
    REQUIRE(expected == actual);
  }
}
