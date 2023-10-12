#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 2, 3},
          .nums2{2, 4, 6},
          .expected{{1, 3}, {4, 6}},
      },
      {
          .nums1{1, 2, 3, 3},
          .nums2{1, 1, 2, 2},
          .expected{{3}, {}},
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    auto actual = Solution::findDifference(nums1, nums2);
    for (auto &a : actual) {
      std::sort(a.begin(), a.end());
    }
    REQUIRE(expected == actual);
  }
}
