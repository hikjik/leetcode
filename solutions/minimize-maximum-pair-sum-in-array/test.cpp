#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 5, 2, 3},
          .expected = 7,
      },
      {
          .nums{3, 5, 4, 2, 4, 6},
          .expected = 8,
      },
  };

  SECTION("Sorting") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = sorting::Solution::minPairSum(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting Sort") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = counting_sort::Solution::minPairSum(nums);
      REQUIRE(expected == actual);
    }
  }

  SECTION("STL") {
    for (const auto &[nums, expected] : test_cases) {
      const auto actual = stl::Solution::minPairSum(nums);
      REQUIRE(expected == actual);
    }
  }
}
