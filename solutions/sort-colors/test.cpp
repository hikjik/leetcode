#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 0, 2, 1, 1, 0},
          .expected{0, 0, 1, 1, 2, 2},
      },
      {
          .nums{2, 0, 1},
          .expected{0, 1, 2},
      },
  };

  SECTION("Iterators") {
    for (auto &[nums, expected] : test_cases) {
      iterators::Solution::sortColors(nums);
      REQUIRE(expected == nums);
    }
  }

  SECTION("Counting Sort") {
    for (auto &[nums, expected] : test_cases) {
      counting_sort::Solution::sortColors(nums);
      REQUIRE(expected == nums);
    }
  }
}
