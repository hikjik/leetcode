#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> costs;
    int k;
    int candidates;
    long long expected;
  };

  std::vector<TestCase> test_cases{
      {
          .costs{17, 12, 10, 2, 7, 2, 11, 20, 8},
          .k = 3,
          .candidates = 4,
          .expected = 11,
      },
      {
          .costs{1, 2, 4, 1},
          .k = 3,
          .candidates = 3,
          .expected = 4,
      },
  };

  for (const auto &[costs, k, candidates, expected] : test_cases) {
    const auto actual = Solution::totalCost(costs, k, candidates);
    REQUIRE(expected == actual);
  }
}
