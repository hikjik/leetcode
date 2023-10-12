#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    int k;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 3, 3, 2},
          .nums2{2, 1, 3, 4},
          .k = 3,
          .expected = 12,
      },
      {
          .nums1{4, 2, 3, 1, 1},
          .nums2{7, 5, 10, 9, 6},
          .k = 1,
          .expected = 30,
      },
  };

  for (const auto &[nums1, nums2, k, expected] : test_cases) {
    const auto actual = Solution::maxScore(nums1, nums2, k);
    REQUIRE(expected == actual);
  }
}
