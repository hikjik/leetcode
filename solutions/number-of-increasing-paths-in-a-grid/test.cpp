#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 1}, {3, 4}},
          .expected = 8,
      },
      {
          .grid{{1}, {2}},
          .expected = 3,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::countPaths(grid);
    REQUIRE(expected == actual);
  }
}
