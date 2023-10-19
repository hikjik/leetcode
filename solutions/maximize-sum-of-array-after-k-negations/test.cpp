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
          .nums{3, -1, 0, 2},
          .k = 3,
          .expected = 6,
      },
      {
          .nums{4, 2, 3},
          .k = 1,
          .expected = 5,
      },
      {
          .nums{2, -3, -1, 5, -4},
          .k = 2,
          .expected = 13,
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::largestSumAfterKNegations(nums, k);
    REQUIRE(expected == actual);
  }
}
