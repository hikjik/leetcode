#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>
#include <vector>

template <class T>
void CheckSorted(std::vector<T> expected, std::vector<T> actual) {
  std::sort(expected.begin(), expected.end());
  std::sort(actual.begin(), actual.end());
  REQUIRE(expected == actual);
}

TEST_CASE("Simple") {
  {
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;
    std::vector<int> expected{0, 1};
    CheckSorted(expected, Solution::twoSum(nums, target));
  }
  {
    std::vector<int> nums{3, 2, 4};
    int target = 6;
    std::vector<int> expected{1, 2};
    CheckSorted(expected, Solution::twoSum(nums, target));
  }
  {
    std::vector<int> nums{3, 3};
    int target = 6;
    std::vector<int> expected{0, 1};
    CheckSorted(expected, Solution::twoSum(nums, target));
  }
}
