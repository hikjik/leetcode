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
          .nums1{55, 30, 5, 4, 2},
          .nums2{100, 20, 10, 10, 5},
          .expected = 2,
      },
      {
          .nums1{2, 2, 2},
          .nums2{10, 10, 1},
          .expected = 1,
      },
      {
          .nums1{30, 29, 19, 5},
          .nums2{25, 25, 25, 25, 25},
          .expected = 2,
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::maxDistance(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
