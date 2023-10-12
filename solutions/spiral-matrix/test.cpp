#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .expected{1, 2, 3, 6, 9, 8, 7, 4, 5},
      },
      {
          .matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
          .expected{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7},
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::spiralOrder(matrix);
    REQUIRE(expected == actual);
  }
}
