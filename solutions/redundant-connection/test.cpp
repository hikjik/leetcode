#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> edges;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .edges{{1, 2}, {1, 3}, {2, 3}},
          .expected{2, 3},
      },
      {
          .edges{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}},
          .expected{1, 4},
      },
  };

  for (const auto &[edges, expected] : test_cases) {
    const auto actual = Solution::findRedundantConnection(edges);
    REQUIRE(expected == actual);
  }
}
