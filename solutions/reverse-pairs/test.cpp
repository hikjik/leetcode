#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 2, 3, 1},
          .expected = 2,
      },
      {
          .nums{2, 4, 3, 5, 1},
          .expected = 3,
      },
  };

  SECTION("Ordered Set") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = ordered_set::Solution::reversePairs(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Merge Sort") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = merge_sort::Solution::reversePairs(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Fenwick Tree") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = fenwick_tree::Solution::reversePairs(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Segment Tree") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual =
          segment_tree::Solution::reversePairs(nums);
      REQUIRE(expected == actual);
    }
  }
}
