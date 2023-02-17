#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    std::vector<int> nums2{2, 5, 6};
    std::vector<int> expected{1, 2, 2, 3, 5, 6};
    Solution::merge(nums1, 3, nums2, 3);
    REQUIRE(expected == nums1);
  }
  {
    std::vector<int> nums1{1};
    std::vector<int> nums2;
    std::vector<int> expected{1};
    Solution::merge(nums1, 1, nums2, 0);
    REQUIRE(expected == nums1);
  }
  {
    std::vector<int> nums1{0};
    std::vector<int> nums2{1};
    std::vector<int> expected{1};
    Solution::merge(nums1, 0, nums2, 1);
    REQUIRE(expected == nums1);
  }
}
