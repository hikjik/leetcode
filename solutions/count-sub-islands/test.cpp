#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid1;
    std::vector<std::vector<int>> grid2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid1{{1, 1, 1, 0, 0},
                 {0, 1, 1, 1, 1},
                 {0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {1, 1, 0, 1, 1}},
          .grid2{{1, 1, 1, 0, 0},
                 {0, 0, 1, 1, 1},
                 {0, 1, 0, 0, 0},
                 {1, 0, 1, 1, 0},
                 {0, 1, 0, 1, 0}},
          .expected = 3,
      },
      {
          .grid1{{1, 0, 1, 0, 1},
                 {1, 1, 1, 1, 1},
                 {0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1},
                 {1, 0, 1, 0, 1}},
          .grid2{{0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1},
                 {0, 1, 0, 1, 0},
                 {0, 1, 0, 1, 0},
                 {1, 0, 0, 0, 1}},
          .expected = 2,
      },
  };

  for (const auto &[grid1, grid2, expected] : test_cases) {
    const auto actual = Solution::countSubIslands(grid1, grid2);
    REQUIRE(expected == actual);
  }
}
