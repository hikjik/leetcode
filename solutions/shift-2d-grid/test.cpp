#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .k = 1,
          .expected{{9, 1, 2}, {3, 4, 5}, {6, 7, 8}},
      },
      {
          .grid{{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}},
          .k = 4,
          .expected{
              {12, 0, 21, 13}, {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}},
      },
      {
          .grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .k = 9,
          .expected{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      },
      {
          .grid{{1}},
          .k = 100,
          .expected{{1}},
      },
  };

  for (const auto &[grid, k, expected] : test_cases) {
    const auto actual = Solution::shiftGrid(grid, k);
    REQUIRE(expected == actual);
  }
}
