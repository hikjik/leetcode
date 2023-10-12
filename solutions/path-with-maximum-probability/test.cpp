#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    std::vector<double> succProb;
    int start_node;
    int end_node;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .edges{{0, 1}, {1, 2}, {0, 2}},
          .succProb{0.5, 0.5, 0.2},
          .start_node = 0,
          .end_node = 2,
          .expected = 0.25000,
      },
      {
          .n = 3,
          .edges{{0, 1}, {1, 2}, {0, 2}},
          .succProb{0.5, 0.5, 0.3},
          .start_node = 0,
          .end_node = 2,
          .expected = 0.30000,
      },
      {
          .n = 3,
          .edges{{0, 1}},
          .succProb{0.5},
          .start_node = 0,
          .end_node = 2,
          .expected = 0.00000,
      },
  };

  for (const auto &[n, edges, succProb, start_node, end_node, expected] :
       test_cases) {
    const auto actual =
        Solution::maxProbability(n, edges, succProb, start_node, end_node);
    REQUIRE(expected == Approx(actual));
  }
}
