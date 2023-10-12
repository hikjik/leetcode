#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
          .expected = 7,
      },
      {
          .grid{{1, 2, 3}, {4, 5, 6}},
          .expected = 12,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::minPathSum(grid);
    REQUIRE(expected == actual);
  }
}
