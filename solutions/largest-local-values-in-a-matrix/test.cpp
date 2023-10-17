#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}},
          .expected{{9, 9}, {8, 6}},
      },
      {
          .grid{{1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 2, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1}},
          .expected{{2, 2, 2}, {2, 2, 2}, {2, 2, 2}},
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::largestLocal(grid);
    REQUIRE(expected == actual);
  }
}
