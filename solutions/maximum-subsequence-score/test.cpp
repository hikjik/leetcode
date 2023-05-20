#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3;
    std::vector<int> nums1{1, 3, 3, 2};
    std::vector<int> nums2{2, 1, 3, 4};
    REQUIRE(12 == Solution::maxScore(nums1, nums2, k));
  }
  {
    int k = 1;
    std::vector<int> nums1{4, 2, 3, 1, 1};
    std::vector<int> nums2{7, 5, 10, 9, 6};
    REQUIRE(30 == Solution::maxScore(nums1, nums2, k));
  }
}
