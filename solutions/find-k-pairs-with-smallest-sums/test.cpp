#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3;
    std::vector<int> nums1{1, 7, 11};
    std::vector<int> nums2{2, 4, 6};
    std::vector<std::vector<int>> expected{{1, 2}, {1, 4}, {1, 6}};
    REQUIRE(expected == Solution::kSmallestPairs(nums1, nums2, k));
  }
  {
    int k = 2;
    std::vector<int> nums1{1, 1, 2};
    std::vector<int> nums2{1, 2, 3};
    std::vector<std::vector<int>> expected{{1, 1}, {1, 1}};
    REQUIRE(expected == Solution::kSmallestPairs(nums1, nums2, k));
  }
  {
    int k = 3;
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3};
    std::vector<std::vector<int>> expected{{1, 3}, {2, 3}};
    REQUIRE(expected == Solution::kSmallestPairs(nums1, nums2, k));
  }
}
