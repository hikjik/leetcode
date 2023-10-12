#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    std::vector<int> newInterval;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .intervals{{1, 3}, {6, 9}},
          .newInterval{2, 5},
          .expected{{1, 5}, {6, 9}},
      },
      {
          .intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}},
          .newInterval{4, 8},
          .expected{{1, 2}, {3, 10}, {12, 16}},
      },
  };

  for (const auto &[intervals, newInterval, expected] : test_cases) {
    const auto actual = Solution::insert(intervals, newInterval);
    REQUIRE(expected == actual);
  }
}
