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
          .nums1{4, 1, 3},
          .nums2{5, 7},
          .expected = 15,
      },
      {
          .nums1{3, 5, 2, 6},
          .nums2{3, 1, 7},
          .expected = 3,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::minNumber(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
