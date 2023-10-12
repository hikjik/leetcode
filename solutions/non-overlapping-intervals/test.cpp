#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}},
          .expected = 1,
      },
      {
          .intervals{{1, 2}, {1, 2}, {1, 2}},
          .expected = 2,
      },
      {
          .intervals{{1, 2}, {2, 3}},
          .expected = 0,
      },
  };

  for (const auto &[intervals, expected] : test_cases) {
    const auto actual = Solution::eraseOverlapIntervals(intervals);
    REQUIRE(expected == actual);
  }
}
