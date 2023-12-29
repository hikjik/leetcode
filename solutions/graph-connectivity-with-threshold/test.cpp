#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int threshold;
    std::vector<std::vector<int>> queries;
    std::vector<bool> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 6,
          .threshold = 2,
          .queries{{1, 4}, {2, 5}, {3, 6}},
          .expected{false, false, true},
      },
      {
          .n = 6,
          .threshold = 0,
          .queries{{4, 5}, {3, 4}, {3, 2}, {2, 6}, {1, 3}},
          .expected{true, true, true, true, true},
      },
      {
          .n = 5,
          .threshold = 1,
          .queries{{4, 5}, {4, 5}, {3, 2}, {2, 3}, {3, 4}},
          .expected{false, false, false, false, false},
      },
  };

  for (const auto &[n, threshold, queries, expected] : test_cases) {
    const auto actual = Solution::areConnected(n, threshold, queries);
    REQUIRE(expected == actual);
  }
}
