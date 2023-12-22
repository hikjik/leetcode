#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> hits;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .grid{{1, 0, 0, 0}, {1, 1, 1, 0}},
          .hits{{1, 0}},
          .expected{2},
      },
      {
          .grid{{1, 0, 0, 0}, {1, 1, 0, 0}},
          .hits{{1, 1}, {1, 0}},
          .expected{0, 0},
      },
  };

  for (const auto &[grid, hits, expected] : test_cases) {
    const auto actual = Solution::hitBricks(grid, hits);
    REQUIRE(expected == actual);
  }
}
