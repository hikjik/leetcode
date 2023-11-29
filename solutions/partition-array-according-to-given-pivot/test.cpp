#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int pivot;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{9, 12, 5, 10, 14, 3, 10},
          .pivot = 10,
          .expected{9, 5, 3, 10, 10, 12, 14},
      },
      {
          .nums{-3, 4, 3, 2},
          .pivot = 2,
          .expected{-3, 2, 4, 3},
      },
  };

  SECTION("STL") {
    for (const auto &[nums, pivot, expected] : test_cases) {
      const auto actual = stl::Solution::pivotArray(nums, pivot);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Pointers") {
    for (const auto &[nums, pivot, expected] : test_cases) {
      const auto actual = pointers::Solution::pivotArray(nums, pivot);
      REQUIRE(expected == actual);
    }
  }
}
