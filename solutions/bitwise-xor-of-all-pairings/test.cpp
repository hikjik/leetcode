#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{2, 1, 3};
    std::vector<int> nums2{10, 2, 5, 0};
    REQUIRE(13 == Solution::xorAllNums(nums1, nums2));
  }
  {
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3, 4};
    REQUIRE(0 == Solution::xorAllNums(nums1, nums2));
  }
}
