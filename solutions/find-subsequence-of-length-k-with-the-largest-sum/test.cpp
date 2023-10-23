#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-8, -94, -30, -98, -27, 62, 26},
          .k = 7,
          .expected{-8, -94, -30, -98, -27, 62, 26},
      },
      {
          .nums{3, 4, 3, 3},
          .k = 2,
          .expected{3, 4},
      },
      {
          .nums{-1, -2, 3, 4},
          .k = 3,
          .expected{-1, 3, 4},
      },
      {
          .nums{2, 1, 3, 3},
          .k = 2,
          .expected{3, 3},
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::maxSubsequence(nums, k);
    REQUIRE(expected == actual);
  }
}
