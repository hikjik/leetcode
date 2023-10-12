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
          .nums1{2, 1, -2, 5},
          .nums2{3, 0, -6},
          .expected = 18,
      },
      {
          .nums1{3, -2},
          .nums2{2, -6, 7},
          .expected = 21,
      },
      {
          .nums1{-1, -1},
          .nums2{1, 1},
          .expected = -1,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::maxDotProduct(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
