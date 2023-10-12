#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}},
          .expected = 2,
      },
      {
          .grid{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}},
          .expected = 4,
      },
      {
          .grid{{0, 1}, {2, 0}},
          .expected = 0,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::uniquePathsIII(grid);
    REQUIRE(expected == actual);
  }
}
