#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    double expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 3},
          .nums2{2},
          .expected = 2.00000,
      },
      {
          .nums1{1, 2},
          .nums2{3, 4},
          .expected = 2.50000,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::findMedianSortedArrays(nums1, nums2);
    REQUIRE(expected == Approx(actual));
  }
}
