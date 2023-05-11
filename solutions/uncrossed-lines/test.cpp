#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{1, 4, 2};
    std::vector<int> nums2{1, 2, 4};
    REQUIRE(2 == Solution::maxUncrossedLines(nums1, nums2));
  }
  {
    std::vector<int> nums1{2, 5, 1, 2, 5};
    std::vector<int> nums2{10, 5, 2, 1, 5, 2};
    REQUIRE(3 == Solution::maxUncrossedLines(nums1, nums2));
  }
  {
    std::vector<int> nums1{1, 3, 7, 1, 7, 5};
    std::vector<int> nums2{1, 9, 2, 5, 1};
    REQUIRE(2 == Solution::maxUncrossedLines(nums1, nums2));
  }
  {
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{1, 1};
    REQUIRE(1 == Solution::maxUncrossedLines(nums1, nums2));
  }
  {
    std::vector<int> nums1{1};
    std::vector<int> nums2{1, 3, 2, 2, 2, 3};
    REQUIRE(1 == Solution::maxUncrossedLines(nums1, nums2));
  }
}
