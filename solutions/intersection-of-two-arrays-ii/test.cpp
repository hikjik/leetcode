#include <catch.hpp>

#include <solution.hpp>

void CheckSolution(std::vector<int> expected, std::vector<int> actual) {
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  REQUIRE(expected == actual);
}

TEST_CASE("Simple") {
  {
    std::vector<int> nums1{1, 2, 2, 1};
    std::vector<int> nums2{2, 2};
    CheckSolution(std::vector<int>{2, 2}, Solution::intersect(nums1, nums2));
  }
  {
    std::vector<int> nums1{4, 9, 5};
    std::vector<int> nums2{9, 4, 9, 8, 4};
    CheckSolution(std::vector<int>{4, 9}, Solution::intersect(nums1, nums2));
  }
}
