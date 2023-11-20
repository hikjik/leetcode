#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 3, 5, 6},
          .expected = 14,
      },
      {
          .nums{5, -1, -3, 8},
          .expected = 13,
      },
      {
          .nums{-2, -1},
          .expected = -1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxBalancedSubsequenceSum(nums);
    REQUIRE(expected == actual);
  }
}
