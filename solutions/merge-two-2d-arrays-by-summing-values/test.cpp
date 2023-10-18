#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> nums1;
    std::vector<std::vector<int>> nums2;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{{1, 2}, {2, 3}, {4, 5}},
          .nums2{{1, 4}, {3, 2}, {4, 1}},
          .expected{{1, 6}, {2, 3}, {3, 2}, {4, 6}},
      },
      {
          .nums1{{2, 4}, {3, 6}, {5, 5}},
          .nums2{{1, 3}, {4, 3}},
          .expected{{1, 3}, {2, 4}, {3, 6}, {4, 3}, {5, 5}},
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::mergeArrays(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
