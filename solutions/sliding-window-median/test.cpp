#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<double> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, -1, -3, 5, 3, 6, 7},
          .k = 3,
          .expected{1.00000, -1.00000, -1.00000, 3.00000, 5.00000, 6.00000},
      },
      {
          .nums{1, 2, 3, 4, 2, 3, 1, 4, 2},
          .k = 3,
          .expected{2.00000, 3.00000, 3.00000, 3.00000, 2.00000, 3.00000,
                    2.00000},
      },
      {
          .nums{1, 2},
          .k = 1,
          .expected{1.00000, 2.00000},
      },
  };

  SECTION("Ordered Set") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = oset::Solution::medianSlidingWindow(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Two MultiSet") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = two_multiset::Solution::medianSlidingWindow(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("MultiSet") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = multiset::Solution::medianSlidingWindow(nums, k);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Two heap") {
    for (const auto &[nums, k, expected] : test_cases) {
      const auto actual = heap::Solution::medianSlidingWindow(nums, k);
      REQUIRE(expected == actual);
    }
  }
}
