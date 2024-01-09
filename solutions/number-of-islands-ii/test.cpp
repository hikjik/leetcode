#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int m;
    int n;
    std::vector<std::vector<int>> positions;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .m = 3,
          .n = 3,
          .positions{{0, 0}, {0, 1}, {1, 2}, {2, 1}},
          .expected{1, 1, 2, 3},
      },
      {
          .m = 1,
          .n = 1,
          .positions{{0, 0}},
          .expected{1},
      },
      {
          .m = 3,
          .n = 3,
          .positions{{0, 0}, {0, 1}, {1, 2}, {2, 1}, {1, 1}},
          .expected{1, 1, 2, 3, 1},
      },
  };

  for (const auto &[m, n, positions, expected] : test_cases) {
    const auto actual = Solution::numIslands2(m, n, positions);
    REQUIRE(expected == actual);
  }
}
