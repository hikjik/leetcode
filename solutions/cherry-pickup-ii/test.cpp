#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}},
          .expected = 24,
      },
      {
          .grid{{1, 0, 0, 0, 0, 0, 1},
                {2, 0, 0, 0, 0, 3, 0},
                {2, 0, 9, 0, 0, 0, 0},
                {0, 3, 0, 5, 4, 0, 0},
                {1, 0, 2, 3, 0, 0, 6}},
          .expected = 28,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::cherryPickup(grid);
    REQUIRE(expected == actual);
  }
}
