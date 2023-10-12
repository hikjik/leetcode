#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .edges{
              {3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}},
          .expected = 2,
      },
      {
          .n = 4,
          .edges{{3, 1, 2}, {3, 2, 3}, {1, 1, 4}, {2, 1, 4}},
          .expected = 0,
      },
      {
          .n = 4,
          .edges{{3, 2, 3}, {1, 1, 2}, {2, 3, 4}},
          .expected = -1,
      },
  };

  for (const auto &[n, edges, expected] : test_cases) {
    const auto actual = Solution::maxNumEdgesToRemove(n, edges);
    REQUIRE(expected == actual);
  }
}
