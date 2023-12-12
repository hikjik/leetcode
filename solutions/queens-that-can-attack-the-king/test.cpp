#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> queens;
    std::vector<int> king;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .queens{{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}},
          .king{0, 0},
          .expected{{0, 1}, {1, 0}, {3, 3}},
      },
      {
          .queens{{0, 0}, {1, 1}, {2, 2}, {3, 4}, {3, 5}, {4, 4}, {4, 5}},
          .king{3, 3},
          .expected{{2, 2}, {3, 4}, {4, 4}},
      },
  };

  for (const auto &[queens, king, expected] : test_cases) {
    const auto actual = Solution::queensAttacktheKing(queens, king);
    REQUIRE(expected == actual);
  }
}
