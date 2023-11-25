#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 3, 5},
          .expected{4, 3, 5},
      },
      {
          .nums{1, 4, 6, 8, 10},
          .expected{24, 15, 13, 15, 21},
      },
  };

  SECTION("Prefix Sum") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = prefix_sum::Solution::getSumAbsoluteDifferences(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Space Optimized") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = optimized::Solution::getSumAbsoluteDifferences(nums);
      REQUIRE(expected == actual);
    }
  }
}
