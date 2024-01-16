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
          .nums{1, 4, 5, 2, 3},
          .k = 3,
          .expected{5, 2, 3},
      },
      {
          .nums{1, 4, 5, 2, 3},
          .k = 4,
          .expected{4, 5, 2, 3},
      },
      {
          .nums{1, 4, 5, 2, 3},
          .k = 1,
          .expected{5},
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::largestSubarray(nums, k);
    REQUIRE(expected == actual);
  }
}
