#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 6,
          .edges{{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}},
          .expected{0, 3},
      },
      {
          .n = 5,
          .edges{{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}},
          .expected{0, 2, 3},
      },
  };

  for (const auto &[n, edges, expected] : test_cases) {
    const auto actual = Solution::findSmallestSetOfVertices(n, edges);
    REQUIRE(expected == actual);
  }
}
