#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{2, 0, 0, 1}, {0, 3, 1, 0}, {0, 5, 2, 0}, {4, 0, 0, 2}},
          .expected = true,
      },
      {
          .grid{{5, 7, 0}, {0, 3, 1}, {0, 5, 0}},
          .expected = false,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::checkXMatrix(grid);
    REQUIRE(expected == actual);
  }
}
