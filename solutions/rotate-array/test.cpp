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
          .nums{1, 2, 3, 4, 5, 6, 7},
          .k = 3,
          .expected{5, 6, 7, 1, 2, 3, 4},
      },
      {
          .nums{-1, -100, 3, 99},
          .k = 2,
          .expected{3, 99, -1, -100},
      },
  };

  for (auto &[nums, k, expected] : test_cases) {
    Solution::rotate(nums, k);
    REQUIRE(expected == nums);
  }
}
