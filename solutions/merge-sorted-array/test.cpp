#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums1{1, 2, 3, 0, 0, 0},
          .m = 3,
          .nums2{2, 5, 6},
          .n = 3,
          .expected{1, 2, 2, 3, 5, 6},
      },
      {
          .nums1{1},
          .m = 1,
          .nums2{},
          .n = 0,
          .expected{1},
      },
      {
          .nums1{0},
          .m = 0,
          .nums2{1},
          .n = 1,
          .expected{1},
      },
  };

  SECTION("Linear") {
    for (auto &[nums1, m, nums2, n, expected] : test_cases) {
      linear::Solution::merge(nums1, m, nums2, n);
      REQUIRE(expected == nums1);
    }
  }

  SECTION("STL") {
    for (auto &[nums1, m, nums2, n, expected] : test_cases) {
      stl::Solution::merge(nums1, m, nums2, n);
      REQUIRE(expected == nums1);
    }
  }
}
