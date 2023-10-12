#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> edgeList;
    std::vector<std::vector<int>> queries;
    std::vector<bool> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .edgeList{{0, 1, 2}, {1, 2, 4}, {2, 0, 8}, {1, 0, 16}},
          .queries{{0, 1, 2}, {0, 2, 5}},
          .expected{false, true},
      },
      {
          .n = 5,
          .edgeList{{0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}},
          .queries{{0, 4, 14}, {1, 4, 13}},
          .expected{true, false},
      },
  };

  for (const auto &[n, edgeList, queries, expected] : test_cases) {
    const auto actual =
        Solution::distanceLimitedPathsExist(n, edgeList, queries);
    REQUIRE(expected == actual);
  }
}
