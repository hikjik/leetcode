#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> graph;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .graph{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}},
          .expected{2, 4, 5, 6},
      },
      {
          .graph{{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}},
          .expected{4},
      },
  };

  for (const auto &[graph, expected] : test_cases) {
    const auto actual = Solution::eventualSafeNodes(graph);
    REQUIRE(expected == actual);
  }
}
