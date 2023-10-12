#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 0, 3, 12},
          .expected{1, 3, 12, 0, 0},
      },
      {
          .nums{0},
          .expected{0},
      },
  };

  for (auto &[nums, expected] : test_cases) {
    Solution::moveZeroes(nums);
    REQUIRE(expected == nums);
  }
}
