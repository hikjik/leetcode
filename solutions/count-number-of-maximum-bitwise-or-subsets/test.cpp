#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 1},
          .expected = 2,
      },
      {
          .nums{2, 2, 2},
          .expected = 7,
      },
      {
          .nums{3, 2, 1, 5},
          .expected = 6,
      },
  };

  SECTION("Backtracking") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = backtracking::Solution::countMaxOrSubsets(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("DP") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = dp::Solution::countMaxOrSubsets(nums);
      REQUIRE(expected == actual);
    }
  }
}
