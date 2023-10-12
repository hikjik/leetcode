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
          .nums1{2, 1, 3},
          .nums2{10, 2, 5, 0},
          .expected = 13,
      },
      {
          .nums1{1, 2},
          .nums2{3, 4},
          .expected = 0,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::xorAllNums(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
