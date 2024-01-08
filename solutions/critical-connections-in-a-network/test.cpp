#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> connections;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 4,
          .connections{{0, 1}, {1, 2}, {2, 0}, {1, 3}},
          .expected{{1, 3}},
      },
      {
          .n = 2,
          .connections{{0, 1}},
          .expected{{0, 1}},
      },
  };

  for (const auto &[n, connections, expected] : test_cases) {
    const auto actual = Solution::criticalConnections(n, connections);
    REQUIRE(expected == actual);
  }
}
