#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5, 6},
          .k = 1,
          .expected = 11,
      },
      {
          .nums{-1, 3, 2, 4, 5},
          .k = 3,
          .expected = 11,
      },
      {
          .nums{-1, -2, -3, -4},
          .k = 2,
          .expected = -6,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::maximumSubarraySum(nums, k);
    REQUIRE(expected == actual);
  }
}
