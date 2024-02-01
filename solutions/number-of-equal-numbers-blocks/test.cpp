#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 1, 1, 3, 9, 9, 9, 2, 10, 10},
          .expected = 5,
      },
      {
          .nums{3, 3, 3, 3, 3},
          .expected = 1,
      },
      {
          .nums{1, 2, 3, 4, 5, 6, 7},
          .expected = 7,
      },
  };

  SECTION("Divide and Conquer") {
    for (const auto &[nums, expected] : test_cases) {
      BigArray bigArray(nums);
      const auto actual = dac::Solution::countBlocks(&bigArray);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Binary Search") {
    for (const auto &[nums, expected] : test_cases) {
      BigArray bigArray(nums);
      const auto actual = bs::Solution::countBlocks(&bigArray);
      REQUIRE(expected == actual);
    }
  }
}
