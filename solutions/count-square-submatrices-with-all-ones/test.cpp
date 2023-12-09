#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}},
          .expected = 15,
      },
      {
          .matrix{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}},
          .expected = 7,
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::countSquares(matrix);
    REQUIRE(expected == actual);
  }
}
