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
          .nums{7, 2, 5, 10, 8},
          .k = 2,
          .expected = 18,
      },
      {
          .nums{1, 2, 3, 4, 5},
          .k = 2,
          .expected = 9,
      },
  };

  SECTION("Binary Search") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = binary_search::Solution::splitArray(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = memo::Solution::splitArray(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = dp::Solution::splitArray(nums, k);
      REQUIRE(expected == actual);
    }
  }
}
