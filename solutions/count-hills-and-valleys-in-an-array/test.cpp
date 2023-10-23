#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 4, 1, 1, 6, 5},
          .expected = 3,
      },
      {
          .nums{6, 6, 5, 5, 4, 1},
          .expected = 0,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::countHillValley(nums);
    REQUIRE(expected == actual);
  }
}
