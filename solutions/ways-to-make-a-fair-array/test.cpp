#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 1, 6, 4},
          .expected = 1,
      },
      {
          .nums{1, 1, 1},
          .expected = 3,
      },
      {
          .nums{1, 2, 3},
          .expected = 0,
      },
  };

  SECTION("Prefix Sum") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = prefix_sum::Solution::waysToMakeFair(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = optimized::Solution::waysToMakeFair(nums);
      REQUIRE(expected == actual);
    }
  }
}
