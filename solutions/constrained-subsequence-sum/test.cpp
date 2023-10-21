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
          .nums{10, 2, -10, 5, 20},
          .k = 2,
          .expected = 37,
      },
      {
          .nums{-1, -2, -3},
          .k = 1,
          .expected = -1,
      },
      {
          .nums{10, -2, -10, -5, 20},
          .k = 2,
          .expected = 23,
      },
      {
          .nums{-7609, 249, -1699, 2385, 9125, -9037, 1107, -8228, 856, -9526},
          .k = 9,
          .expected = 13722,
      },
      {
          .nums{1, -5000, -5000, 5000},
          .k = 2,
          .expected = 5000,
      },
      {
          .nums{-5},
          .k = 1,
          .expected = -5,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::constrainedSubsetSum(nums, k);
    REQUIRE(expected == actual);
  }
}
