#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}},
          .expected = 7,
      },
      {
          .grid{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}},
          .expected = 1,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::findMaxFish(grid);
    REQUIRE(expected == actual);
  }
}
