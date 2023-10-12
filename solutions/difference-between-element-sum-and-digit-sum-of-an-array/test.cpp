#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 15, 6, 3},
          .expected = 9,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::differenceOfSum(nums);
    REQUIRE(expected == actual);
  }
}
