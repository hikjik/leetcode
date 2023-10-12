#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> gas;
    std::vector<int> cost;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .gas{1, 2, 3, 4, 5},
          .cost{3, 4, 5, 1, 2},
          .expected = 3,
      },
      {
          .gas{2, 3, 4},
          .cost{3, 4, 3},
          .expected = -1,
      },
  };

  for (const auto &[gas, cost, expected] : test_cases) {
    const auto actual = Solution::canCompleteCircuit(gas, cost);
    REQUIRE(expected == actual);
  }
}
