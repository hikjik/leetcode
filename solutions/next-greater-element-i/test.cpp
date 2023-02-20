#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{4, 1, 2};
    std::vector<int> nums2{1, 3, 4, 2};
    std::vector<int> expected{-1, 3, -1};
    REQUIRE(expected == Solution::nextGreaterElement(nums1, nums2));
  }
  {
    std::vector<int> nums1{2, 4};
    std::vector<int> nums2{1, 2, 3, 4};
    std::vector<int> expected{3, -1};
    REQUIRE(expected == Solution::nextGreaterElement(nums1, nums2));
  }
}