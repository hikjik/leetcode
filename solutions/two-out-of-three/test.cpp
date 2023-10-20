#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> nums3;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 1, 3, 2},
          .nums2{2, 3},
          .nums3{3},
          .expected{3, 2},
      },
      {
          .nums1{3, 1},
          .nums2{2, 3},
          .nums3{1, 2},
          .expected{2, 3, 1},
      },
      {
          .nums1{1, 2, 2},
          .nums2{4, 3, 3},
          .nums3{5},
          .expected{},
      },
  };

  for (const auto &[nums1, nums2, nums3, expected] : test_cases) {
    const auto actual = Solution::twoOutOfThree(nums1, nums2, nums3);
    REQUIRE(expected == actual);
  }
}
