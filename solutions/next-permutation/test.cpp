#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3},
          .expected{1, 3, 2},
      },
      {
          .nums{3, 2, 1},
          .expected{1, 2, 3},
      },
      {
          .nums{1, 1, 5},
          .expected{1, 5, 1},
      },
  };

  for (auto &[nums, expected] : test_cases) {
    Solution::nextPermutation(nums);
    REQUIRE(expected == nums);
  }
}
