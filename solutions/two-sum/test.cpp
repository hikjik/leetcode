#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 7, 11, 15},
          .target = 9,
          .expected{0, 1},
      },
      {
          .nums{3, 2, 4},
          .target = 6,
          .expected{1, 2},
      },
      {
          .nums{3, 3},
          .target = 6,
          .expected{0, 1},
      },
  };

  SECTION("One-pass Hash Table") {
    for (const auto &[nums, target, expected] : test_cases) {
      auto actual = hash_table::Solution::twoSum(nums, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Two-Pointers Technique") {
    for (const auto &[nums, target, expected] : test_cases) {
      auto actual = two_pointers::Solution::twoSum(nums, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Brute Force") {
    for (const auto &[nums, target, expected] : test_cases) {
      auto actual = brute_force::Solution::twoSum(nums, target);
      REQUIRE(expected == actual);
    }
  }
}
