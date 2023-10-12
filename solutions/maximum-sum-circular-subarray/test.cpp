#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, -2, 3, -2},
          .expected = 3,
      },
      {
          .nums{5, -3, 5},
          .expected = 10,
      },
      {
          .nums{-3, -2, -3},
          .expected = -2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::maxSubarraySumCircular(nums);
    REQUIRE(expected == actual);
  }
}
