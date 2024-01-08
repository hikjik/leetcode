#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 0, 1, 1, 0},
          .expected = 4,
      },
      {
          .nums{1, 0, 1, 1, 0, 1},
          .expected = 4,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findMaxConsecutiveOnes(nums);
    REQUIRE(expected == actual);
  }
}
