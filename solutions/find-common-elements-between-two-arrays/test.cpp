#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{4, 3, 2, 3, 1},
          .nums2{2, 2, 5, 2, 3, 6},
          .expected{3, 4},
      },
      {
          .nums1{3, 4, 2, 3},
          .nums2{1, 5},
          .expected{0, 0},
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::findIntersectionValues(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
