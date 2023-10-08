#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{2, 1, -2, 5}, nums2{3, 0, -6};
    REQUIRE(18 == Solution::maxDotProduct(nums1, nums2));
  }
  {
    std::vector<int> nums1{3, -2}, nums2{2, -6, 7};
    REQUIRE(21 == Solution::maxDotProduct(nums1, nums2));
  }
  {
    std::vector<int> nums1{-1, -1}, nums2{1, 1};
    REQUIRE(-1 == Solution::maxDotProduct(nums1, nums2));
  }
}
