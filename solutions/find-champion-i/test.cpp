#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{0, 1}, {0, 0}},
          .expected = 0,
      },
      {
          .grid{{0, 0, 1}, {1, 0, 1}, {0, 0, 0}},
          .expected = 1,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::findChampion(grid);
    REQUIRE(expected == actual);
  }
}
