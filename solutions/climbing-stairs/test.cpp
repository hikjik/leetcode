#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 2,
          .expected = 2,
      },
      {
          .n = 3,
          .expected = 3,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::climbStairs(n);
    REQUIRE(expected == actual);
  }
}
