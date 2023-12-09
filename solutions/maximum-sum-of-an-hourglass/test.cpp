#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}},
          .expected = 30,
      },
      {
          .grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .expected = 35,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::maxSum(grid);
    REQUIRE(expected == actual);
  }
}
