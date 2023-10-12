#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 7, 11, 15},
          .target = 9,
          .expected{0, 1},
      },
      {
          .nums{3, 2, 4},
          .target = 6,
          .expected{1, 2},
      },
      {
          .nums{3, 3},
          .target = 6,
          .expected{0, 1},
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    auto actual = Solution::twoSum(nums, target);
    REQUIRE(expected == actual);
  }
}
