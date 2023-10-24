#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{8, 1, 2, 2, 3},
          .expected{4, 0, 1, 1, 3},
      },
      {
          .nums{6, 5, 4, 8},
          .expected{2, 1, 0, 3},
      },
      {
          .nums{7, 7, 7, 7},
          .expected{0, 0, 0, 0},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::smallerNumbersThanCurrent(nums);
    REQUIRE(expected == actual);
  }
}
