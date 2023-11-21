#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{42, 11, 1, 97},
          .expected = 2,
      },
      {
          .nums{13, 10, 35, 24, 76},
          .expected = 4,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::countNicePairs(nums);
    REQUIRE(expected == actual);
  }
}
