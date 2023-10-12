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
          .n = 6,
          .connections{{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}},
          .expected = 3,
      },
      {
          .n = 5,
          .connections{{1, 0}, {1, 2}, {3, 2}, {3, 4}},
          .expected = 2,
      },
      {
          .n = 3,
          .connections{{1, 0}, {2, 0}},
          .expected = 0,
      },
  };

  for (const auto &[n, connections, expected] : test_cases) {
    const auto actual = Solution::minReorder(n, connections);
    REQUIRE(expected == actual);
  }
}
