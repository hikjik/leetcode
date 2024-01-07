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
          .nums1{1, 2, 1, 2},
          .nums2{1, 1, 1, 1},
          .expected = 2,
      },
      {
          .nums1{1, 2, 3, 4, 5, 6},
          .nums2{2, 3, 2, 3, 2, 3},
          .expected = 5,
      },
      {
          .nums1{1, 1, 2, 2, 3, 3},
          .nums2{4, 4, 5, 5, 6, 6},
          .expected = 6,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::maximumSetSize(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
