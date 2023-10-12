#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int target;
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .target = 7,
          .nums{2, 3, 1, 2, 4, 3},
          .expected = 2,
      },
      {
          .target = 4,
          .nums{1, 4, 4},
          .expected = 1,
      },
      {
          .target = 11,
          .nums{1, 1, 1, 1, 1, 1, 1, 1},
          .expected = 0,
      },
  };

  for (const auto &[target, nums, expected] : test_cases) {
    const auto actual = Solution::minSubArrayLen(target, nums);
    REQUIRE(expected == actual);
  }
}
