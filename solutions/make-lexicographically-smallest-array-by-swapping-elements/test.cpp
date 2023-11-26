#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int limit;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 5, 3, 9, 8},
          .limit = 2,
          .expected{1, 3, 5, 8, 9},
      },
      {
          .nums{1, 7, 6, 18, 2, 1},
          .limit = 3,
          .expected{1, 6, 7, 18, 1, 2},
      },
      {
          .nums{1, 7, 28, 19, 10},
          .limit = 3,
          .expected{1, 7, 28, 19, 10},
      },
  };

  for (const auto &[nums, limit, expected] : test_cases) {
    const auto actual = Solution::lexicographicallySmallestArray(nums, limit);
    REQUIRE(expected == actual);
  }
}
