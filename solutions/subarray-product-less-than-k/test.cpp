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
          .nums{10, 5, 2, 6},
          .k = 100,
          .expected = 8,
      },
      {
          .nums{1, 2, 3},
          .k = 0,
          .expected = 0,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::numSubarrayProductLessThanK(nums, k);
    REQUIRE(expected == actual);
  }
}
