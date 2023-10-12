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
          .nums{5, 7, 7, 8, 8, 10},
          .target = 8,
          .expected{3, 4},
      },
      {
          .nums{5, 7, 7, 8, 8, 10},
          .target = 6,
          .expected{-1, -1},
      },
      {
          .nums{},
          .target = 0,
          .expected{-1, -1},
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::searchRange(nums, target);
    REQUIRE(expected == actual);
  }
}
