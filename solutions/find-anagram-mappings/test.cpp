#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{12, 28, 46, 32, 50},
          .nums2{50, 12, 32, 46, 28},
          .expected{1, 4, 3, 2, 0},
      },
      {
          .nums1{84, 46},
          .nums2{84, 46},
          .expected{0, 1},
      },
  };

  for (const auto &[nums1, nums2, expected] : test_cases) {
    const auto actual = Solution::anagramMappings(nums1, nums2);
    REQUIRE(expected == actual);
  }
}
