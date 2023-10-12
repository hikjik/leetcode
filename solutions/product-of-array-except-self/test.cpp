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
          .expected{24, 12, 8, 6},
      },
      {
          .nums{-1, 1, 0, -3, 3},
          .expected{0, 0, 9, 0, 0},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::productExceptSelf(nums);
    REQUIRE(expected == actual);
  }
}
