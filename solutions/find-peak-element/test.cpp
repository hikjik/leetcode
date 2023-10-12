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
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 1},
          .expected = 2,
      },
      {
          .nums{1, 2, 1, 3, 5, 6, 4},
          .expected = 5,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findPeakElement(nums);
    REQUIRE(isPeakElement(nums, actual));
  }
}
