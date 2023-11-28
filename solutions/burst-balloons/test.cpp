#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 1, 5, 8},
          .expected = 167,
      },
      {
          .nums{1, 5},
          .expected = 10,
      },
  };

  SECTION("Tabulation") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = dp::Solution::maxCoins(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = memo::Solution::maxCoins(nums);
      REQUIRE(expected == actual);
    }
  }
}
