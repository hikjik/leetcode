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
          .expected = 6,
      },
      {
          .matrix{{'0'}},
          .expected = 0,
      },
      {
          .matrix{{'1'}},
          .expected = 1,
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::maximalRectangle(matrix);
    REQUIRE(expected == actual);
  }
}
