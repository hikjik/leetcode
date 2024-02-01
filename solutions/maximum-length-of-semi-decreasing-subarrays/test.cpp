#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{7, 6, 5, 4, 3, 2, 1, 6, 10, 11},
          .expected = 8,
      },
      {
          .nums{57, 55, 50, 60, 61, 58, 63, 59, 64, 60, 63},
          .expected = 6,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = 0,
      },
  };

  SECTION("Sorting") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = sorting::Solution::maxSubarrayLength(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Stack") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = stack::Solution::maxSubarrayLength(nums);
      REQUIRE(expected == actual);
    }
  }
}
