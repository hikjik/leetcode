#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}},
          .expected = 7,
      },
      {
          .grid{{0, 2, 4}, {3, 2, 1}, {1, 0, 4}},
          .expected = -1,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::minimumTime(grid);
    REQUIRE(expected == actual);
  }
}
