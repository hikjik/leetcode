#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{5, 3, 4, 2},
          .nums2{4, 2, 2, 5},
          .expected = 40,
      },
      {
          .nums1{2, 1, 4, 5, 7},
          .nums2{3, 2, 4, 8, 6},
          .expected = 65,
      },
  };

  SECTION("Sorting") {
    for (const auto &[nums1, nums2, expected] : test_cases) {
      const auto actual = sorting::Solution::minProductSum(nums1, nums2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Counting") {
    for (const auto &[nums1, nums2, expected] : test_cases) {
      const auto actual = counting::Solution::minProductSum(nums1, nums2);
      REQUIRE(expected == actual);
    }
  }
}
