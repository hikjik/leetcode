#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> roads;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .roads{{0, 1}, {0, 3}, {1, 2}, {1, 3}},
          .expected = 4,
      },
      {
          .n = 5,
          .roads{{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}},
          .expected = 5,
      },
      {
          .n = 8,
          .roads{{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}},
          .expected = 5,
      },
  };

  for (const auto &[n, roads, expected] : test_cases) {
    const auto actual = Solution::maximalNetworkRank(n, roads);
    REQUIRE(expected == actual);
  }
}
