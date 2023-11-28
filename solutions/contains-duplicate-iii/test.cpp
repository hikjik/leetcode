#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int indexDiff;
    int valueDiff;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 1},
          .indexDiff = 3,
          .valueDiff = 0,
          .expected = true,
      },
      {
          .nums{1, 5, 9, 1, 5, 9},
          .indexDiff = 2,
          .valueDiff = 3,
          .expected = false,
      },
  };

  SECTION("Set") {
    for (const auto &[nums, indexDiff, valueDiff, expected] : test_cases) {
      const auto actual = set::Solution::containsNearbyAlmostDuplicate(
          nums, indexDiff, valueDiff);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Bucket") {
    for (const auto &[nums, indexDiff, valueDiff, expected] : test_cases) {
      const auto actual = bucket::Solution::containsNearbyAlmostDuplicate(
          nums, indexDiff, valueDiff);
      REQUIRE(expected == actual);
    }
  }
}
