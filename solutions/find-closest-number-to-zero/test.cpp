#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-4, -2, 1, 4, 8},
          .expected = 1,
      },
      {
          .nums{2, -1, 1},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findClosestNumber(nums);
    REQUIRE(expected == actual);
  }
}
