#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 2, 2, 3, 4},
          .expected = true,
      },
      {
          .nums{1, 1, 1, 1},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::isPossibleToSplit(nums);
    REQUIRE(expected == actual);
  }
}
