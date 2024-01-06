#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    int n;
    std::vector<int> wells;
    std::vector<std::vector<int>> pipes;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .n = 3,
          .wells{1, 2, 2},
          .pipes{{1, 2, 1}, {2, 3, 1}},
          .expected = 3,
      },
      {
          .n = 2,
          .wells{1, 1},
          .pipes{{1, 2, 1}, {1, 2, 2}},
          .expected = 2,
      },
  };

  for (const auto &[n, wells, pipes, expected] : test_cases) {
    const auto actual = Solution::minCostToSupplyWater(n, wells, pipes);
    REQUIRE(expected == actual);
  }
}
