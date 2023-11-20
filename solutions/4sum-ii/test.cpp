#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> nums3;
    std::vector<int> nums4;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 2},
          .nums2{-2, -1},
          .nums3{-1, 2},
          .nums4{0, 2},
          .expected = 2,
      },
      {
          .nums1{0},
          .nums2{0},
          .nums3{0},
          .nums4{0},
          .expected = 1,
      },
  };

  for (const auto &[nums1, nums2, nums3, nums4, expected] : test_cases) {
    const auto actual = Solution::fourSumCount(nums1, nums2, nums3, nums4);
    REQUIRE(expected == actual);
  }
}
