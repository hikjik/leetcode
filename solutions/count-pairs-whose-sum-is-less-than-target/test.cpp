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
          .nums{-1, 1, 2, 3, 1},
          .target = 2,
          .expected = 3,
      },
      {
          .nums{-6, 2, 5, -2, -7, -1, 3},
          .target = -2,
          .expected = 10,
      },
  };

  for (const auto &[nums, target, expected] : test_cases) {
    const auto actual = Solution::countPairs(nums, target);
    REQUIRE(expected == actual);
  }
}
