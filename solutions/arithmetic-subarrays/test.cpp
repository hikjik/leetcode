#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> l;
    std::vector<int> r;
    std::vector<bool> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{4, 6, 5, 9, 3, 7},
          .l{0, 0, 2},
          .r{2, 3, 5},
          .expected{true, false, true},
      },
      {
          .nums{-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10},
          .l{0, 1, 6, 4, 8, 7},
          .r{4, 4, 9, 7, 9, 10},
          .expected{false, true, false, false, true, true},
      },
  };

  SECTION("Sorting") {
    for (const auto &[nums, l, r, expected] : test_cases) {
      const auto actual =
          sorting::Solution::checkArithmeticSubarrays(nums, l, r);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Hash Table") {
    for (const auto &[nums, l, r, expected] : test_cases) {
      const auto actual =
          hash_table::Solution::checkArithmeticSubarrays(nums, l, r);
      REQUIRE(expected == actual);
    }
  }
}
