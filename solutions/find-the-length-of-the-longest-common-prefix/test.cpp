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
          .nums1{1, 10, 100},
          .nums2{1000},
          .expected = 3,
      },
      {
          .nums1{1, 2, 3},
          .nums2{4, 4, 4},
          .expected = 0,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::longestCommonPrefix(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
