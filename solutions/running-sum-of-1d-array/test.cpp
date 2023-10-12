#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4},
          .expected{1, 3, 6, 10},
      },
      {
          .nums{1, 1, 1, 1, 1},
          .expected{1, 2, 3, 4, 5},
      },
      {
          .nums{3, 1, 2, 10, 1},
          .expected{3, 4, 6, 16, 17},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::runningSum(nums);
    REQUIRE(expected == actual);
  }
}
