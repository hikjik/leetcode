#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> connections;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .connections{{1, 2, 5}, {1, 3, 6}, {2, 3, 1}},
          .expected = 6,
      },
      {
          .n = 4,
          .connections{{1, 2, 3}, {3, 4, 4}},
          .expected = -1,
      },
  };

  for (const auto &[n, connections, expected] : test_cases) {
    const auto actual = Solution::minimumCost(n, connections);
    REQUIRE(expected == actual);
  }
}
