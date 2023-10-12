#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int k;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{7, 4, 3, 9, 1, 8, 5, 2, 6},
          .k = 3,
          .expected{-1, -1, -1, 5, 4, 4, -1, -1, -1},
      },
      {
          .nums{100000},
          .k = 0,
          .expected{100000},
      },
      {
          .nums{8},
          .k = 100000,
          .expected{-1},
      },
  };

  for (const auto &[nums, k, expected] : test_cases) {
    const auto actual = Solution::getAverages(nums, k);
    REQUIRE(expected == actual);
  }
}
