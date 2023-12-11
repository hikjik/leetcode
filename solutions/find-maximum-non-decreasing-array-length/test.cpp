#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{272, 482, 115, 925, 983},
          .expected = 4,
      },
      {
          .nums{5, 2, 2},
          .expected = 1,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = 4,
      },
      {
          .nums{4, 3, 2, 6},
          .expected = 3,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::findMaximumLength(nums);
    REQUIRE(expected == actual);
  }
}
