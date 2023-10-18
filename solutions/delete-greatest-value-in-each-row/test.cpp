#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 2, 4}, {3, 3, 1}},
          .expected = 8,
      },
      {
          .grid{{10}},
          .expected = 10,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::deleteGreatestValue(grid);
    REQUIRE(expected == actual);
  }
}
