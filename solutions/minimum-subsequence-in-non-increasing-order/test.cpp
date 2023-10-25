#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 3, 10, 9, 8},
          .expected{10, 9},
      },
      {
          .nums{4, 4, 7, 6, 7},
          .expected{7, 7, 6},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minSubsequence(nums);
    REQUIRE(expected == actual);
  }
}
