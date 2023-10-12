#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 12,
          .expected = 3,
      },
      {
          .n = 13,
          .expected = 2,
      },
  };

  for (const auto &[n, expected] : test_cases) {
    const auto actual = Solution::numSquares(n);
    REQUIRE(expected == actual);
  }
}
