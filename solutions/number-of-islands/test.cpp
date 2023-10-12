#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}},
          .expected = 1,
      },
      {
          .grid{{'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}},
          .expected = 3,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::numIslands(grid);
    REQUIRE(expected == actual);
  }
}
