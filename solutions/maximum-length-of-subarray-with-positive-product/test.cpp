#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, -2, -3, 4},
          .expected = 4,
      },
      {
          .nums{0, 1, -2, -3, -4},
          .expected = 3,
      },
      {
          .nums{-1, -2, -3, 0, 1},
          .expected = 2,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::getMaxLen(nums);
    REQUIRE(expected == actual);
  }
}
