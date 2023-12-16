#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}},
          .expected = 24,
      },
      {
          .grid{{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}},
          .expected = 28,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::getMaximumGold(grid);
    REQUIRE(expected == actual);
  }
}
