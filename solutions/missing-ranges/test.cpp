#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int lower;
    int upper;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 3, 50, 75},
          .lower = 0,
          .upper = 99,
          .expected{{2, 2}, {4, 49}, {51, 74}, {76, 99}},
      },
      {
          .nums{2, 3, 4, 8},
          .lower = 0,
          .upper = 10,
          .expected{{0, 1}, {5, 7}, {9, 10}},
      },
      {
          .nums{-1},
          .lower = -1,
          .upper = -1,
          .expected{},
      },
      {
          .nums{},
          .lower = 1,
          .upper = 1,
          .expected{{1, 1}},
      },
      {
          .nums{},
          .lower = 1,
          .upper = 3,
          .expected{{1, 3}},
      },
      {
          .nums{2},
          .lower = 1,
          .upper = 3,
          .expected{{1, 1}, {3, 3}},
      },
  };

  for (const auto &[nums, lower, upper, expected] : test_cases) {
    const auto actual = Solution::findMissingRanges(nums, lower, upper);
    REQUIRE(expected == actual);
  }
}
