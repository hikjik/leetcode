#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 3, 2, 3, 5, 2, 1},
          .k = 4,
          .expected = true,
      },
      {
          .nums{1, 2, 3, 4},
          .k = 3,
          .expected = false,
      },
      {
          .nums{1, 1, 1, 1, 2, 2, 2, 2},
          .k = 4,
          .expected = true,
      },
  };

  SECTION("Memoization") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = memo::Solution::canPartitionKSubsets(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = dp::Solution::canPartitionKSubsets(nums, k);
      REQUIRE(expected == actual);
    }
  }
}
