#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{0, 2}, {1, 3}},
          .expected = 3,
      },
      {
          .grid{{0, 1, 2, 3, 4},
                {24, 23, 22, 21, 5},
                {12, 13, 14, 15, 16},
                {11, 17, 18, 19, 20},
                {10, 9, 8, 7, 6}},
          .expected = 16,
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::swimInWater(grid);
    REQUIRE(expected == actual);
  }
}
