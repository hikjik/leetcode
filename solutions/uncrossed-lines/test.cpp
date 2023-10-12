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
          .nums1{1, 4, 2},
          .nums2{1, 2, 4},
          .expected = 2,
      },
      {
          .nums1{2, 5, 1, 2, 5},
          .nums2{10, 5, 2, 1, 5, 2},
          .expected = 3,
      },
      {
          .nums1{1, 3, 7, 1, 7, 5},
          .nums2{1, 9, 2, 5, 1},
          .expected = 2,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::maxUncrossedLines(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
