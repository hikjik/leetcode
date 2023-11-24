#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int lower;
    int upper;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{0, 1, 7, 4, 4, 5},
          .lower = 3,
          .upper = 6,
          .expected = 6,
      },
      {
          .nums{1, 7, 9, 2, 5},
          .lower = 11,
          .upper = 11,
          .expected = 1,
      },
  };

  SECTION("STL") {
    for (const auto &[nums, lower, upper, expected] : test_cases) {
      const auto actual = stl::Solution::countFairPairs(nums, lower, upper);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Two Pointers") {
    for (const auto &[nums, lower, upper, expected] : test_cases) {
      const auto actual =
          two_pointers::Solution::countFairPairs(nums, lower, upper);
      REQUIRE(expected == actual);
    }
  }
}
