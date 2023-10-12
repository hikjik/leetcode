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
          .nums1{1, 7, 5},
          .nums2{2, 3, 5},
          .expected = 3,
      },
      {
          .nums1{2, 4, 6, 8, 10},
          .nums2{2, 4, 6, 8, 10},
          .expected = 0,
      },
      {
          .nums1{1, 10, 4, 4, 2, 7},
          .nums2{9, 3, 5, 1, 7, 4},
          .expected = 20,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::minAbsoluteSumDiff(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
