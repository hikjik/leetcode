#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .expected = false,
      },
      {
          .nums{3, 1, 4, 2},
          .expected = true,
      },
      {
          .nums{-1, 3, 2, 0},
          .expected = true,
      },
      {
          .nums{1, 0, 1, -4, -3},
          .expected = false,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::find132pattern(nums);
    REQUIRE(expected == actual);
  }
}
