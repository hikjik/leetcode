#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matches;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matches{{1, 3},
                   {2, 3},
                   {3, 6},
                   {5, 6},
                   {5, 7},
                   {4, 5},
                   {4, 8},
                   {4, 9},
                   {10, 4},
                   {10, 9}},
          .expected{{1, 2, 10}, {4, 5, 7, 8}},
      },
      {
          .matches{{2, 3}, {1, 3}, {5, 4}, {6, 4}},
          .expected{{1, 2, 5, 6}, {}},
      },
  };

  for (const auto &[matches, expected] : test_cases) {
    const auto actual = Solution::findWinners(matches);
    REQUIRE(expected == actual);
  }
}
