#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> cost;
    std::vector<int> time;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .cost{1, 2, 3, 2},
          .time{1, 2, 3, 2},
          .expected = 3,
      },
      {
          .cost{2, 3, 4, 2},
          .time{1, 1, 1, 1},
          .expected = 4,
      },
  };

  for (const auto &[cost, time, expected] : test_cases) {
    const auto actual = Solution::paintWalls(cost, time);
    REQUIRE(expected == actual);
  }
}
