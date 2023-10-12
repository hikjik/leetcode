#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{3, 2, 1}, {1, 7, 6}, {2, 7, 7}},
          .expected = 1,
      },
      {
          .grid{{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}},
          .expected = 3,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::equalPairs(grid);
    REQUIRE(expected == actual);
  }
}
