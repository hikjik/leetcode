#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 0, -1, 0, -2, 2},
          .target = 0,
          .expected{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}},
      },
      {
          .nums{2, 2, 2, 2, 2},
          .target = 8,
          .expected{{2, 2, 2, 2}},
      },
      {
          .nums{0, 0, 0, 0},
          .target = 0,
          .expected{{0, 0, 0, 0}},
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::fourSum(nums, target);
    REQUIRE(expected == actual);
  }
}
