#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    int source;
    int destination;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .edges{{0, 1}, {0, 2}},
          .source = 0,
          .destination = 2,
          .expected = false,
      },
      {
          .n = 4,
          .edges{{0, 1}, {0, 3}, {1, 2}, {2, 1}},
          .source = 0,
          .destination = 3,
          .expected = false,
      },
      {
          .n = 4,
          .edges{{0, 1}, {0, 2}, {1, 3}, {2, 3}},
          .source = 0,
          .destination = 3,
          .expected = true,
      },
  };

  for (const auto &[n, edges, source, destination, expected] : test_cases) {
    const auto actual =
        Solution::leadsToDestination(n, edges, source, destination);
    REQUIRE(expected == actual);
  }
}
