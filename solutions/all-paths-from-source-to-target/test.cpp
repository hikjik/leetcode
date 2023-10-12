#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .graph{{1, 2}, {3}, {3}, {}},
          .expected{{0, 1, 3}, {0, 2, 3}},
      },
      {
          .graph{{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}},
          .expected{
              {0, 4}, {0, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 4}},
      },
  };

  for (const auto &[graph, expected] : test_cases) {
    const auto actual = Solution::allPathsSourceTarget(graph);
    REQUIRE(expected == actual);
  }
}
