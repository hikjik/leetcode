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
          .nums{1, 2, 4},
          .k = 5,
          .expected = 3,
      },
      {
          .nums{1, 4, 8, 13},
          .k = 5,
          .expected = 2,
      },
      {
          .nums{3, 9, 6},
          .k = 2,
          .expected = 1,
      },
  };

  SECTION("Sliding Window") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = sliding_window::Solution::maxFrequency(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Sliding Window + Counting Sort") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = counting_sort::Solution::maxFrequency(nums, k);
      REQUIRE(expected == actual);
    }
  }
}
