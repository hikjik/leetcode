#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    int diff;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{3, 2, 5},
          .nums2{2, 2, 1},
          .diff = 1,
          .expected = 3,
      },
      {
          .nums1{3, -1},
          .nums2{-2, 2},
          .diff = -1,
          .expected = 0,
      },
  };

  SECTION("Ordered Set") {
    for (const auto &[nums1, nums2, diff, expected] : test_cases) {
      const auto actual =
          ordered_set::Solution::numberOfPairs(nums1, nums2, diff);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Merge Sort") {
    for (const auto &[nums1, nums2, diff, expected] : test_cases) {
      const auto actual =
          merge_sort::Solution::numberOfPairs(nums1, nums2, diff);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Fenwick Tree") {
    for (const auto &[nums1, nums2, diff, expected] : test_cases) {
      const auto actual =
          fenwick_tree::Solution::numberOfPairs(nums1, nums2, diff);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Segment Tree") {
    for (const auto &[nums1, nums2, diff, expected] : test_cases) {
      const auto actual =
          segment_tree::Solution::numberOfPairs(nums1, nums2, diff);
      REQUIRE(expected == actual);
    }
  }
}
