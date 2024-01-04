#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{34, 23, 1, 24, 75, 33, 54, 8},
          .k = 60,
          .expected = 58,
      },
      {
          .nums{10, 20, 30},
          .k = 15,
          .expected = -1,
      },
  };

  SECTION("Brute Force") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = bf::Solution::twoSumLessThanK(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Sorting") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = sorting::Solution::twoSumLessThanK(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = counting::Solution::twoSumLessThanK(nums, k);
      REQUIRE(expected == actual);
    }
  }
}
