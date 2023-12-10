#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 1, 2, 3, 1, 2},
          .k = 2,
          .expected = 6,
      },
      {
          .nums{1, 2, 1, 2, 1, 2, 1, 2},
          .k = 1,
          .expected = 2,
      },
      {
          .nums{5, 5, 5, 5, 5, 5, 5},
          .k = 4,
          .expected = 4,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::maxSubarrayLength(nums, k);
    REQUIRE(expected == actual);
  }
}
