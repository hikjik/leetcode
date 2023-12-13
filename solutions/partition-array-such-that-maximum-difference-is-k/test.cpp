#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 6, 1, 2, 5},
          .k = 2,
          .expected = 2,
      },
      {
          .nums{1, 2, 3},
          .k = 1,
          .expected = 2,
      },
      {
          .nums{2, 2, 4, 5},
          .k = 0,
          .expected = 3,
      },
  };

  SECTION("Sorting") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = sorting::Solution::partitionArray(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = counting::Solution::partitionArray(nums, k);
      REQUIRE(expected == actual);
    }
  }
}
