#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{1, 7, 5};
    std::vector<int> nums2{2, 3, 5};
    REQUIRE(3 == Solution::minAbsoluteSumDiff(nums1, nums2));
  }
  {
    std::vector<int> nums1{2, 4, 6, 8, 10};
    std::vector<int> nums2{2, 4, 6, 8, 10};
    REQUIRE(0 == Solution::minAbsoluteSumDiff(nums1, nums2));
  }
  {
    std::vector<int> nums1{1, 10, 4, 4, 2, 7};
    std::vector<int> nums2{9, 3, 5, 1, 7, 4};
    REQUIRE(20 == Solution::minAbsoluteSumDiff(nums1, nums2));
  }
}
