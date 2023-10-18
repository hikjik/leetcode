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
          .nums1{1, 2, 3},
          .nums2{2, 4},
          .expected = 2,
      },
      {
          .nums1{1, 2, 3, 6},
          .nums2{2, 3, 4, 5},
          .expected = 2,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::getCommon(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
