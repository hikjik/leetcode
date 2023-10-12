#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<std::vector<int>> queries;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .queries{{1, 1, 2, 2}, {0, 0, 1, 1}},
          .expected{{1, 1, 0}, {1, 2, 1}, {0, 1, 1}},
      },
      {
          .n = 2,
          .queries{{0, 0, 1, 1}},
          .expected{{1, 1}, {1, 1}},
      },
  };

  for (const auto &[n, queries, expected] : test_cases) {
    const auto actual = Solution::rangeAddQueries(n, queries);
    REQUIRE(expected == actual);
  }
}
