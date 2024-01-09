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
          .n = 5,
          .edges{{0, 1}, {1, 2}, {3, 4}},
          .expected = 2,
      },
      {
          .n = 5,
          .edges{{0, 1}, {1, 2}, {2, 3}, {3, 4}},
          .expected = 1,
      },
  };

  for (const auto &[n, edges, expected] : test_cases) {
    const auto actual = Solution::countComponents(n, edges);
    REQUIRE(expected == actual);
  }
}
