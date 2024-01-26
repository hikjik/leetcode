#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{2, 6, 4, 8, 10, 9, 15},
          .expected = 5,
      },
      {
          .nums{1, 2, 3, 4},
          .expected = 0,
      },
      {
          .nums{1},
          .expected = 0,
      },
  };

  SECTION("Sorting") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = sorting::Solution::findUnsortedSubarray(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Without Sorting") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = opt::Solution::findUnsortedSubarray(nums);
      REQUIRE(expected == actual);
    }
  }
}
