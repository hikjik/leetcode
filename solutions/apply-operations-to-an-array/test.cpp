#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 2, 1, 1, 0},
          .expected{1, 4, 2, 0, 0, 0},
      },
      {
          .nums{0, 1},
          .expected{1, 0},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::applyOperations(nums);
    REQUIRE(expected == actual);
  }
}
