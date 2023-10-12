#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3},
          .target = 4,
          .expected = 7,
      },
      {
          .nums{9},
          .target = 3,
          .expected = 0,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::combinationSum4(nums, target);
    REQUIRE(expected == actual);
  }
}
