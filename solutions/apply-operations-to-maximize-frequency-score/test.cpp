#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    long long k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 6, 4},
          .k = 3,
          .expected = 3,
      },
      {
          .nums{1, 4, 4, 2, 4},
          .k = 0,
          .expected = 3,
      },
  };

  SECTION("Sliding Window") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = sw::Solution::maxFrequencyScore(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Binary Search") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = bs::Solution::maxFrequencyScore(nums, k);
      REQUIRE(expected == actual);
    }
  }
}
