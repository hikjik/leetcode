#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3, 4, 5},
          .expected{-3, -1, 1, 3, 5},
      },
      {
          .nums{3, 2, 3, 4, 2},
          .expected{-2, -1, 0, 2, 3},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::distinctDifferenceArray(nums);
    REQUIRE(expected == actual);
  }
}
