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
          .nums1{1, 2},
          .nums2{2, 3},
          .expected = 2,
      },
      {
          .nums1{1, 0, 3},
          .nums2{5, 3, 4},
          .expected = 8,
      },
  };

  SECTION("Memoization") {
    for (const auto &[nums1, nums2, expected] : test_cases) {
      const auto actual = memo::Solution::minimumXORSum(nums1, nums2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Tabulation") {
    for (const auto &[nums1, nums2, expected] : test_cases) {
      const auto actual = dp::Solution::minimumXORSum(nums1, nums2);
      REQUIRE(expected == actual);
    }
  }
}
