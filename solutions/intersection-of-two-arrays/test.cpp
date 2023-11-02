#include <catch.hpp>

#include <solution.hpp>

#include <algorithm>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 2, 2, 1},
          .nums2{2, 2},
          .expected{2},
      },
      {
          .nums1{4, 9, 5},
          .nums2{9, 4, 9, 8, 4},
          .expected{4, 9},
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::intersection(nums1, nums2);
    REQUIRE_THAT(expected, Catch::Matchers::UnorderedEquals(actual));
  }
}
