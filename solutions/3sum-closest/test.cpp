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
          .nums{-1, 2, 1, -4},
          .target = 1,
          .expected = 2,
      },
      {
          .nums{0, 0, 0},
          .target = 1,
          .expected = 0,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::threeSumClosest(nums, target);
    REQUIRE(expected == actual);
  }
}
