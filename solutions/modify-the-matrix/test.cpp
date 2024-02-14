#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{1, 2, -1}, {4, -1, 6}, {7, 8, 9}},
          .expected{{1, 2, 9}, {4, 8, 6}, {7, 8, 9}},
      },
      {
          .matrix{{3, -1}, {5, 2}},
          .expected{{3, 2}, {5, 2}},
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::modifiedMatrix(matrix);
    REQUIRE(expected == actual);
  }
}
