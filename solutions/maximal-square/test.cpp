#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<char>> matrix;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{'1', '0', '1', '0', '0'},
                  {'1', '0', '1', '1', '1'},
                  {'1', '1', '1', '1', '1'},
                  {'1', '0', '0', '1', '0'}},
          .expected = 4,
      },
      {
          .matrix{{'0', '1'}, {'1', '0'}},
          .expected = 1,
      },
      {
          .matrix{{'0'}},
          .expected = 0,
      },
  };

  SECTION("DP") {
    for (const auto &[matrix, expected] : test_cases) {
      const auto actual = dp::Solution::maximalSquare(matrix);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[matrix, expected] : test_cases) {
      const auto actual = optimized::Solution::maximalSquare(matrix);
      REQUIRE(expected == actual);
    }
  }
}
