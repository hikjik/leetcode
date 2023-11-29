#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{3, 1, -2, -5, 2, -4},
          .expected{3, -2, 1, -5, 2, -4},
      },
      {
          .nums{4, 3, 2, 1, -4, -3, -2, -1},
          .expected{4, -4, 3, -3, 2, -2, 1, -1},
      },
      {
          .nums{-1, 1},
          .expected{1, -1},
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::rearrangeArray(nums);
    REQUIRE(expected == actual);
  }
}
