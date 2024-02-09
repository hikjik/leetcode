#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    int x;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{20, 1, 15},
          .x = 5,
          .expected = 13,
      },
      {
          .nums{1, 2, 3},
          .x = 4,
          .expected = 6,
      },
  };

  for (const auto &[nums, x, expected] : test_cases) {
    const auto actual = Solution::minCost(nums, x);
    REQUIRE(expected == actual);
  }
}
