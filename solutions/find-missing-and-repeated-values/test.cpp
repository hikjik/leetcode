#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 3}, {2, 2}},
          .expected{2, 4},
      },
      {
          .grid{{9, 1, 7}, {8, 9, 2}, {3, 4, 6}},
          .expected{9, 5},
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::findMissingAndRepeatedValues(grid);
    REQUIRE(expected == actual);
  }
}
