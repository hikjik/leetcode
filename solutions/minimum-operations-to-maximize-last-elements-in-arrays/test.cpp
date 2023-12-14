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
          .nums1{1, 2, 7},
          .nums2{4, 5, 3},
          .expected = 1,
      },
      {
          .nums1{2, 3, 4, 5, 9},
          .nums2{8, 8, 4, 4, 4},
          .expected = 2,
      },
      {
          .nums1{1, 5, 4},
          .nums2{2, 5, 3},
          .expected = -1,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::minOperations(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
