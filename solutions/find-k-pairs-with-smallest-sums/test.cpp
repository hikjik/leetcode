#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 7, 11},
          .nums2{2, 4, 6},
          .k = 3,
          .expected{{1, 2}, {1, 4}, {1, 6}},
      },
      {
          .nums1{1, 1, 2},
          .nums2{1, 2, 3},
          .k = 2,
          .expected{{1, 1}, {1, 1}},
      },
      {
          .nums1{1, 2},
          .nums2{3},
          .k = 3,
          .expected{{1, 3}, {2, 3}},
      },
  };

  for (const auto &[nums1, nums2, k, expected] : test_cases) {
    const auto actual = Solution::kSmallestPairs(nums1, nums2, k);
    REQUIRE(expected == actual);
  }
}
