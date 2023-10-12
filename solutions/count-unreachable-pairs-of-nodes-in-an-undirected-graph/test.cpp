#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .edges{{0, 1}, {0, 2}, {1, 2}},
          .expected = 0,
      },
      {
          .n = 7,
          .edges{{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}},
          .expected = 14,
      },
  };

  for (const auto &[n, edges, expected] : test_cases) {
    const auto actual = Solution::countPairs(n, edges);
    REQUIRE(expected == actual);
  }
}
