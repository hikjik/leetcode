#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    int x;
    int y;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .x = 1,
          .y = 3,
          .expected{6, 0, 0},
      },
      {
          .n = 5,
          .x = 2,
          .y = 4,
          .expected{10, 8, 2, 0, 0},
      },
      {
          .n = 4,
          .x = 1,
          .y = 1,
          .expected{6, 4, 2, 0},
      },
  };

  for (const auto &[n, x, y, expected] : test_cases) {
    const auto actual = Solution::countOfPairs(n, x, y);
    REQUIRE(expected == actual);
  }
}
