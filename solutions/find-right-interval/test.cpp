#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .intervals{{1, 2}},
          .expected{-1},
      },
      {
          .intervals{{3, 4}, {2, 3}, {1, 2}},
          .expected{-1, 0, 1},
      },
      {
          .intervals{{1, 4}, {2, 3}, {3, 4}},
          .expected{-1, 2, -1},
      },
  };

  for (const auto &[intervals, expected] : test_cases) {
    const auto actual = Solution::findRightInterval(intervals);
    REQUIRE(expected == actual);
  }
}
