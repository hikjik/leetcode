#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int lower;
    int upper;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-2, 5, -1},
          .lower = -2,
          .upper = 2,
          .expected = 3,
      },
      {
          .nums{0},
          .lower = 0,
          .upper = 0,
          .expected = 1,
      },
      {
          .nums{0, -3, -3, 1, 1, 2},
          .lower = 3,
          .upper = 5,
          .expected = 2,
      },
  };

  SECTION("Ordered Set") {
    for (const auto &[nums, lower, upper, expected] : test_cases) {
      const auto actual = o_set::Solution::countRangeSum(nums, lower, upper);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Merge Sort") {
    for (const auto &[nums, lower, upper, expected] : test_cases) {
      const auto actual =
          merge_sort::Solution::countRangeSum(nums, lower, upper);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Fenwick Tree") {
    for (const auto &[nums, lower, upper, expected] : test_cases) {
      const auto actual = bit::Solution::countRangeSum(nums, lower, upper);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Segment Tree") {
    for (const auto &[nums, lower, upper, expected] : test_cases) {
      const auto actual =
          segment_tree::Solution::countRangeSum(nums, lower, upper);
      REQUIRE(expected == actual);
    }
  }
}
