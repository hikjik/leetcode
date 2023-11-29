#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5},
          .expected = 5,
      },
      {
          .nums{1, 2, 3, 4, 5},
          .expected = 8,
      },
  };

  SECTION("Math") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = math::Solution::triangularSum(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Brute Force") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = brute_force::Solution::triangularSum(nums);
      REQUIRE(expected == actual);
    }
  }
}
