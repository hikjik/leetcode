#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> nums;
    std::vector<int> cost;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .nums{1, 3, 5, 2},
          .cost{2, 3, 1, 14},
          .expected = 8,
      },
      {
          .nums{2, 2, 2, 2, 2},
          .cost{4, 2, 8, 1, 3},
          .expected = 0,
      },
  };

  for (const auto &[nums, cost, expected] : test_cases) {
    const auto actual = Solution::minCost(nums, cost);
    REQUIRE(expected == actual);
  }
}
