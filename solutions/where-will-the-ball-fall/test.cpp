#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 1, 1, -1, -1},
                {1, 1, 1, -1, -1},
                {-1, -1, -1, 1, 1},
                {1, 1, 1, 1, -1},
                {-1, -1, -1, -1, -1}},
          .expected{1, -1, -1, -1, -1},
      },
      {
          .grid{{-1}},
          .expected{-1},
      },
      {
          .grid{{1, 1, 1, 1, 1, 1},
                {-1, -1, -1, -1, -1, -1},
                {1, 1, 1, 1, 1, 1},
                {-1, -1, -1, -1, -1, -1}},
          .expected{0, 1, 2, 3, 4, -1},
      },
  };

  for (const auto &[grid, expected] : test_cases) {
    const auto actual = Solution::findBall(grid);
    REQUIRE(expected == actual);
  }
}
