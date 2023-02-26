#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{55, 30, 5, 4, 2};
    std::vector<int> nums2{100, 20, 10, 10, 5};
    int distance = 2;
    REQUIRE(distance == Solution::maxDistance(nums1, nums2));
  }
  {
    std::vector<int> nums1{2, 2, 2};
    std::vector<int> nums2{10, 10, 1};
    int distance = 1;
    REQUIRE(distance == Solution::maxDistance(nums1, nums2));
  }
  {
    std::vector<int> nums1{30, 29, 19, 5};
    std::vector<int> nums2{25, 25, 25, 25, 25};
    int distance = 2;
    REQUIRE(distance == Solution::maxDistance(nums1, nums2));
  }
}
