#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{1, 2, 3};
    std::vector<int> nums2{2, 4, 6};
    std::vector<std::vector<int>> expected{{1, 3}, {4, 6}};
    auto actual = Solution::findDifference(nums1, nums2);
    for (auto &arr : actual) {
      std::sort(arr.begin(), arr.end());
    }
    REQUIRE(expected == actual);
  }
  {
    std::vector<int> nums1{1, 2, 3, 3};
    std::vector<int> nums2{1, 1, 2, 2};
    std::vector<std::vector<int>> expected{{3}, {}};
    auto actual = Solution::findDifference(nums1, nums2);
    for (auto &arr : actual) {
      std::sort(arr.begin(), arr.end());
    }
    REQUIRE(expected == actual);
  }
}
