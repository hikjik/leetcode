#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edges;
    std::vector<bool> hasApple;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 7,
          .edges{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}},
          .hasApple{false, false, true, false, true, true, false},
          .expected = 8,
      },
      {
          .n = 7,
          .edges{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}},
          .hasApple{false, false, true, false, false, true, false},
          .expected = 6,
      },
      {
          .n = 7,
          .edges{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}},
          .hasApple{false, false, false, false, false, false, false},
          .expected = 0,
      },
  };

  for (const auto &[n, edges, hasApple, expected] : test_cases) {
    const auto actual = Solution::minTime(n, edges, hasApple);
    REQUIRE(expected == actual);
  }
}
