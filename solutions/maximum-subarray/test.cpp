#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-2, 1, -3, 4, -1, 2, 1, -5, 4},
          .expected = 6,
      },
      {
          .nums{1},
          .expected = 1,
      },
      {
          .nums{5, 4, -1, 7, 8},
          .expected = 23,
      },
  };

  SECTION("Dynamic Programming") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = dp::Solution::maxSubArray(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Kadane's Algorithm") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = kadane::Solution::maxSubArray(nums);
      REQUIRE(expected == actual);
    }
  }
}
