#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> multipliers;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3},
          .multipliers{3, 2, 1},
          .expected = 14,
      },
      {
          .nums{-5, -3, -3, -2, 7, 1},
          .multipliers{-10, -5, 3, 4, 6},
          .expected = 102,
      },
  };

  SECTION("Memoization") {
    for (const auto &[nums, multipliers, expected] : test_cases) {
      const auto actual = memo::Solution::maximumScore(nums, multipliers);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[nums, multipliers, expected] : test_cases) {
      const auto actual = dp::Solution::maximumScore(nums, multipliers);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Space optimized") {
    for (const auto &[nums, multipliers, expected] : test_cases) {
      const auto actual = opt::Solution::maximumScore(nums, multipliers);
      REQUIRE(expected == actual);
    }
  }
}
