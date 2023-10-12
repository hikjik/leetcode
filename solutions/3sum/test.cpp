#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{-1, 0, 1, 2, -1, -4},
          .expected{{-1, -1, 2}, {-1, 0, 1}},
      },
      {
          .nums{0, 1, 1},
          .expected{},
      },
      {
          .nums{0, 0, 0},
          .expected{{0, 0, 0}},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::threeSum(nums);
    REQUIRE(expected == actual);
  }
}
