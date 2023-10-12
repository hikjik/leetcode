#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-4, -1, 0, 3, 10},
          .expected{0, 1, 9, 16, 100},
      },
      {
          .nums{-7, -3, 2, 3, 11},
          .expected{4, 9, 9, 49, 121},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::sortedSquares(nums);
    REQUIRE(expected == actual);
  }
}
