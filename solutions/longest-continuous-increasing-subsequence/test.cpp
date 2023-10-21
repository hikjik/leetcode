#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 5, 4, 7},
          .expected = 3,
      },
      {
          .nums{2, 2, 2, 2, 2},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findLengthOfLCIS(nums);
    REQUIRE(expected == actual);
  }
}
