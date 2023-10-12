#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int k;
    int row;
    int column;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .k = 2,
          .row = 0,
          .column = 0,
          .expected = 0.06250,
      },
      {
          .n = 1,
          .k = 0,
          .row = 0,
          .column = 0,
          .expected = 1.00000,
      },
  };

  for (const auto &[n, k, row, column, expected] : test_cases) {
    const auto actual = Solution::knightProbability(n, k, row, column);
    REQUIRE(expected == Approx(actual));
  }
}
