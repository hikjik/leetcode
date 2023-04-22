#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{1, 3};
    std::vector<int> nums2{2};
    REQUIRE(2.00000 == Solution::findMedianSortedArrays(nums1, nums2));
  }
  {
    std::vector<int> nums1{2};
    std::vector<int> nums2{1, 3};
    REQUIRE(2.00000 == Solution::findMedianSortedArrays(nums1, nums2));
  }
  {
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3, 4};
    REQUIRE(2.50000 == Solution::findMedianSortedArrays(nums1, nums2));
  }
  {
    std::vector<int> nums1{2};
    std::vector<int> nums2;
    REQUIRE(2.00000 == Solution::findMedianSortedArrays(nums1, nums2));
  }
  {
    std::vector<int> nums1;
    std::vector<int> nums2{1, 2, 3, 4};
    REQUIRE(2.50000 == Solution::findMedianSortedArrays(nums1, nums2));
  }
}
