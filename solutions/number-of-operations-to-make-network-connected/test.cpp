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
          .n = 4,
          .connections{{0, 1}, {0, 2}, {1, 2}},
          .expected = 1,
      },
      {
          .n = 6,
          .connections{{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}},
          .expected = 2,
      },
      {
          .n = 6,
          .connections{{0, 1}, {0, 2}, {0, 3}, {1, 2}},
          .expected = -1,
      },
  };

  for (const auto &[n, connections, expected] : test_cases) {
    const auto actual = Solution::makeConnected(n, connections);
    REQUIRE(expected == actual);
  }
}
