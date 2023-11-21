#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 2, 3},
          .expected = 3,
      },
      {
          .nums{1, 1, 1},
          .expected = 0,
      },
      {
          .nums{1, 1, 1000000000},
          .expected = 999999999,
      },
  };

  for (const auto &[nums, expected] : test_cases) {
    const auto actual = Solution::minMoves(nums);
    REQUIRE(expected == actual);
  }
}