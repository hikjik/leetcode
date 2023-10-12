#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> graph;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .graph{{1, 2, 3}, {0}, {0}, {0}},
          .expected = 4,
      },
      {
          .graph{{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}},
          .expected = 4,
      },
  };

  for (const auto &[graph, expected] : test_cases) {
    const auto actual = Solution::shortestPathLength(graph);
    REQUIRE(expected == actual);
  }
}
