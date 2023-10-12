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
          .nums1{4, 1, 2},
          .nums2{1, 3, 4, 2},
          .expected{-1, 3, -1},
      },
      {
          .nums1{2, 4},
          .nums2{1, 2, 3, 4},
          .expected{3, -1},
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::nextGreaterElement(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
