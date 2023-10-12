#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 5, 11, 5},
          .expected = true,
      },
      {
          .nums{1, 2, 3, 5},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::canPartition(nums);
    REQUIRE(expected == actual);
  }
}
