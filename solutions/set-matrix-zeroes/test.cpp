#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
          .expected{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}},
      },
      {
          .matrix{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
          .expected{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}},
      },
  };

  for (auto &[matrix, expected] : test_cases) {
    Solution::setZeroes(matrix);
    REQUIRE(expected == matrix);
  }
}
