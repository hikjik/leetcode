#include <catch.hpp>

#include <solution.hpp>

bool isPeakElement(const std::vector<int> &nums, size_t i) {
  if (nums.size() == 1) {
    return i == 0;
  }
  if (i == 0 && nums[i] > nums[i + 1]) {
    return true;
  }
  if (i == nums.size() - 1 && nums[i - 1] < nums[i]) {
    return true;
  }
  return nums[i - 1] < nums[i] && nums[i] > nums[i + 1];
}

TEST_CASE("Simple") {
  {
    std::vector<int> nums{1, 2, 3, 1};
    const auto peak = Solution::findPeakElement(nums);
    REQUIRE(isPeakElement(nums, peak));
  }
  {
    std::vector<int> nums{1, 2, 1, 3, 5, 6, 4};
    const auto peak = Solution::findPeakElement(nums);
    REQUIRE(isPeakElement(nums, peak));
  }
  {
    std::vector<int> nums{1};
    const auto peak = Solution::findPeakElement(nums);
    REQUIRE(isPeakElement(nums, peak));
  }
  {
    std::vector<int> nums{1, 2, 3, 4};
    const auto peak = Solution::findPeakElement(nums);
    REQUIRE(isPeakElement(nums, peak));
  }
  {
    std::vector<int> nums{1, 2, 3, 4, 5};
    const auto peak = Solution::findPeakElement(nums);
    REQUIRE(isPeakElement(nums, peak));
  }
  {
    std::vector<int> nums{4, 3, 2, 1};
    const auto peak = Solution::findPeakElement(nums);
    REQUIRE(isPeakElement(nums, peak));
  }
  {
    std::vector<int> nums{5, 4, 3, 2, 1};
    const auto peak = Solution::findPeakElement(nums);
    REQUIRE(isPeakElement(nums, peak));
  }
}
