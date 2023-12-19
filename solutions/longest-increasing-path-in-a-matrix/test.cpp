#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}},
          .expected = 4,
      },
      {
          .matrix{{3, 4, 5}, {3, 2, 6}, {2, 2, 1}},
          .expected = 4,
      },
      {
          .matrix{{1}},
          .expected = 1,
      },
  };

  SECTION("Topological Sort + DP") {
    for (const auto &[matrix, expected] : test_cases) {
      const auto actual = topo::Solution::longestIncreasingPath(matrix);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Memoization") {
    for (const auto &[matrix, expected] : test_cases) {
      const auto actual = memo::Solution::longestIncreasingPath(matrix);
      REQUIRE(expected == actual);
    }
  }
}
