#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> moveCost;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{5, 3}, {4, 0}, {2, 1}},
          .moveCost{{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}},
          .expected = 17,
      },
      {
          .grid{{5, 1, 2}, {4, 0, 3}},
          .moveCost{{12, 10, 15},
                    {20, 23, 8},
                    {21, 7, 1},
                    {8, 1, 13},
                    {9, 10, 25},
                    {5, 3, 2}},
          .expected = 6,
      },
  };

  for (const auto &[grid, moveCost, expected] : test_cases) {
    const auto actual = Solution::minPathCost(grid, moveCost);
    REQUIRE(expected == actual);
  }
}
