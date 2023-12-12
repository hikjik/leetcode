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
          .n = 3,
          .edges{{0, 1}, {1, 2}},
          .expected = 0,
      },
      {
          .n = 4,
          .edges{{0, 2}, {1, 3}, {1, 2}},
          .expected = -1,
      },
  };

  for (const auto &[n, edges, expected] : test_cases) {
    const auto actual = Solution::findChampion(n, edges);
    REQUIRE(expected == actual);
  }
}
