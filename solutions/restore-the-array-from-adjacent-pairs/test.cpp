#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> adjacentPairs;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .adjacentPairs{{2, 1}, {3, 4}, {3, 2}},
          .expected{1, 2, 3, 4},
      },
      {
          .adjacentPairs{{4, -2}, {1, 4}, {-3, 1}},
          .expected{-2, 4, 1, -3},
      },
      {
          .adjacentPairs{{100000, -100000}},
          .expected{100000, -100000},
      },
  };

  for (const auto &[adjacentPairs, expected] : test_cases) {
    auto actual = Solution::restoreArray(adjacentPairs);
    if (actual != expected) {
      std::reverse(actual.begin(), actual.end());
    }
    REQUIRE(expected == actual);
  }
}
