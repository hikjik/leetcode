#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}},
          .expected = 35,
      },
      {
          .grid{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
          .expected = 0,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::maxIncreaseKeepingSkyline(grid);
    REQUIRE(expected == actual);
  }
}
