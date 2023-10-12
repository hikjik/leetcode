#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{10, 4, 8, 3},
          .expected{15, 1, 11, 22},
      },
      {
          .nums{1},
          .expected{0},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::leftRightDifference(nums);
    REQUIRE(expected == actual);
  }
}
