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
          .edges{{0, 1}, {1, 2}, {2, 0}},
          .source = 0,
          .destination = 2,
          .expected = true,
      },
      {
          .n = 6,
          .edges{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}},
          .source = 0,
          .destination = 5,
          .expected = false,
      },
  };

  for (const auto &[n, edges, source, destination, expected] : test_cases) {
    const auto actual = Solution::validPath(n, edges, source, destination);
    REQUIRE(expected == actual);
  }
}
