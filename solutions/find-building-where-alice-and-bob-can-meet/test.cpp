#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> heights;
    std::vector<std::vector<int>> queries;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .heights{6, 4, 8, 5, 2, 7},
          .queries{{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}},
          .expected{2, 5, -1, 5, 2},
      },
      {
          .heights{5, 3, 8, 2, 6, 1, 4, 6},
          .queries{{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}},
          .expected{7, 6, -1, 4, 6},
      },
  };

  for (const auto &[heights, queries, expected] : test_cases) {
    const auto actual = Solution::leftmostBuildingQueries(heights, queries);
    REQUIRE(expected == actual);
  }
}
