#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{3, 2, 0, 1, 0},
          .nums2{6, 5, 0},
          .expected = 12,
      },
      {
          .nums1{2, 0, 2, 0},
          .nums2{1, 4},
          .expected = -1,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::minSum(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
