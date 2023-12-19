#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{6, 7},
          .nums2{6, 0, 4},
          .k = 5,
          .expected{6, 7, 6, 0, 4},
      },
      {
          .nums1{3, 4, 6, 5},
          .nums2{9, 1, 2, 5, 8, 3},
          .k = 5,
          .expected{9, 8, 6, 5, 3},
      },
      {
          .nums1{3, 9},
          .nums2{8, 9},
          .k = 3,
          .expected{9, 8, 9},
      },
      {
          .nums1{2, 5, 6, 4, 4, 0},
          .nums2{7, 3, 8, 0, 6, 5, 7, 6, 2},
          .k = 15,
          .expected{7, 3, 8, 2, 5, 6, 4, 4, 0, 6, 5, 7, 6, 2, 0},
      },
  };

  for (const auto &[nums1, nums2, k, expected] : test_cases) {
    const auto actual = Solution::maxNumber(nums1, nums2, k);
    REQUIRE(expected == actual);
  }
}
