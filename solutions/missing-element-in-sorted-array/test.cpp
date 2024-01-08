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
          .nums{4, 7, 9, 10},
          .k = 1,
          .expected = 5,
      },
      {
          .nums{4, 7, 9, 10},
          .k = 3,
          .expected = 8,
      },
      {
          .nums{1, 2, 4},
          .k = 3,
          .expected = 6,
      },
  };

  SECTION("Linear") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = linear::Solution::missingElement(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Binary Search") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = bs::Solution::missingElement(nums, k);
      REQUIRE(expected == actual);
    }
  }
}
