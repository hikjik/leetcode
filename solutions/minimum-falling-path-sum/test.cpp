#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}},
          .expected = 13,
      },
      {
          .matrix{{-19, 57}, {-40, -5}},
          .expected = -59,
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::minFallingPathSum(matrix);
    REQUIRE(expected == actual);
  }
}
