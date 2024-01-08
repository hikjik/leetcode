#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int target;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 4, 5, 5, 5, 5, 5, 6, 6},
          .target = 5,
          .expected = true,
      },
      {
          .nums{10, 100, 101, 101},
          .target = 101,
          .expected = false,
      },
  };

  SECTION("One Line") {
    for (const auto &[nums, target, expected] : test_cases) {
      const auto actual = one_line::Solution::isMajorityElement(nums, target);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Binary Search") {
    for (const auto &[nums, target, expected] : test_cases) {
      const auto actual = bs::Solution::isMajorityElement(nums, target);
      REQUIRE(expected == actual);
    }
  }
}
