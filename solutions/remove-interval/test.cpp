#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> intervals;
    std::vector<int> toBeRemoved;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .intervals{{0, 2}, {3, 4}, {5, 7}},
          .toBeRemoved{1, 6},
          .expected{{0, 1}, {6, 7}},
      },
      {
          .intervals{{0, 5}},
          .toBeRemoved{2, 3},
          .expected{{0, 2}, {3, 5}},
      },
      {
          .intervals{{-5, -4}, {-3, -2}, {1, 2}, {3, 5}, {8, 9}},
          .toBeRemoved{-1, 4},
          .expected{{-5, -4}, {-3, -2}, {4, 5}, {8, 9}},
      },
  };

  for (const auto &[intervals, toBeRemoved, expected] : test_cases) {
    const auto actual = Solution::removeInterval(intervals, toBeRemoved);
    REQUIRE(expected == actual);
  }
}
