#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int goal;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 0, 1, 0, 1},
          .goal = 2,
          .expected = 4,
      },
      {
          .nums{0, 0, 0, 0, 0},
          .goal = 0,
          .expected = 15,
      },
  };

  SECTION("Prefix Sum") {
    for (const auto &[nums, goal, expected] : test_cases) {
      const auto actual = ps::Solution::numSubarraysWithSum(nums, goal);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Sliding Window") {
    for (const auto &[nums, goal, expected] : test_cases) {
      const auto actual = sw::Solution::numSubarraysWithSum(nums, goal);
      REQUIRE(expected == actual);
    }
  }
}
