#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 2, 3, 2, 1},
          .nums2{3, 2, 1, 4, 7},
          .expected = 3,
      },
      {
          .nums1{0, 0, 0, 0, 0},
          .nums2{0, 0, 0, 0, 0},
          .expected = 5,
      },
  };

  SECTION("DP") {
    for (const auto &[nums1, nums2, expected] : test_cases) {
      const auto actual = dp::Solution::findLength(nums1, nums2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[nums1, nums2, expected] : test_cases) {
      const auto actual = optimized::Solution::findLength(nums1, nums2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("BinarySearch + Hashing") {
    for (const auto &[nums1, nums2, expected] : test_cases) {
      const auto actual = hash::Solution::findLength(nums1, nums2);
      REQUIRE(expected == actual);
    }
  }
}
