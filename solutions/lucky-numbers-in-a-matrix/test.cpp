#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<int> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{3, 7, 8}, {9, 11, 13}, {15, 16, 17}},
          .expected{15},
      },
      {
          .matrix{{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}},
          .expected{12},
      },
      {
          .matrix{{7, 8}, {1, 2}},
          .expected{7},
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::luckyNumbers(matrix);
    REQUIRE(expected == actual);
  }
}
