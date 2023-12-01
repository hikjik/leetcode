#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<int> rowSum;
    std::vector<int> colSum;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .rowSum{3, 8},
          .colSum{4, 7},
          .expected{{3, 0}, {1, 7}},
      },
      {
          .rowSum{5, 7, 10},
          .colSum{8, 6, 8},
          .expected{{5, 0, 0}, {3, 4, 0}, {0, 2, 8}},
      },
  };

  for (const auto &[rowSum, colSum, expected] : test_cases) {
    const auto actual = Solution::restoreMatrix(rowSum, colSum);
    REQUIRE(expected == actual);
  }
}
