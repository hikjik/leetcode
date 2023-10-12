#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 0},
          .expected = 3,
      },
      {
          .nums{3, 4, -1, 1},
          .expected = 2,
      },
      {
          .nums{7, 8, 9, 11, 12},
          .expected = 1,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::firstMissingPositive(nums);
    REQUIRE(expected == actual);
  }
}
