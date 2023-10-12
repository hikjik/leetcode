#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{5, 2, 3, 1},
          .expected{1, 2, 3, 5},
      },
      {
          .nums{5, 1, 1, 2, 0, 0},
          .expected{0, 0, 1, 1, 2, 5},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::sortArray(nums);
    REQUIRE(expected == actual);
  }
}
