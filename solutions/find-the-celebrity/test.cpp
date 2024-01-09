#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> graph;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .graph{{1, 1, 0}, {0, 1, 0}, {1, 1, 1}},
          .expected = 1,
      },
      {
          .graph{{1, 0, 1}, {1, 1, 0}, {0, 1, 1}},
          .expected = -1,
      },
  };

  for (const auto &[graph, expected] : test_cases) {
    const int n = graph.size();

    int calls = 0;
    knows = [&](int i, int j) {
      ++calls;
      return graph[i][j];
    };

    REQUIRE(expected == Solution::findCelebrity(n));
    REQUIRE(calls <= 3 * n);
  }
}
