#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{0, 1, -1}, {1, 0, -1}, {1, 1, 1}},
          .expected = 5,
      },
      {
          .grid{{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}},
          .expected = 0,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::cherryPickup(grid);
    REQUIRE(expected == actual);
  }
}
