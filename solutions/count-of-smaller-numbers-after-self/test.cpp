#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 2, 6, 1},
          .expected{2, 1, 1, 0},
      },
      {
          .nums{-1},
          .expected{0},
      },
      {
          .nums{-1, -1},
          .expected{0, 0},
      },
  };

  SECTION("Ordered Set") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = o_set::Solution::countSmaller(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Merge Sort") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = merge_sort::Solution::countSmaller(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Fenwick Tree") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = bit::Solution::countSmaller(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Segment Tree") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = segment_tree::Solution::countSmaller(nums);
      REQUIRE(expected == actual);
    }
  }
}
