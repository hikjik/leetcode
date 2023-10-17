#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> logs;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 10,
          .logs{{0, 3}, {2, 5}, {0, 9}, {1, 15}},
          .expected = 1,
      },
      {
          .n = 26,
          .logs{{1, 1}, {3, 7}, {2, 12}, {7, 17}},
          .expected = 3,
      },
      {
          .n = 2,
          .logs{{0, 10}, {1, 20}},
          .expected = 0,
      },
  };

  for (const auto &[n, logs, expected] : test_cases) {
    const auto actual = Solution::hardestWorker(n, logs);
    REQUIRE(expected == actual);
  }
}
