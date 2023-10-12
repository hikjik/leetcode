#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> graph;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .graph{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}},
          .expected = false,
      },
      {
          .graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}},
          .expected = true,
      },
  };

  for (const auto &[graph, expected] : test_cases) {
    const auto actual = Solution::isBipartite(graph);
    REQUIRE(expected == actual);
  }
}
