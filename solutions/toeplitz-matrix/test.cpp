#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}},
          .expected = true,
      },
      {
          .matrix{{1, 2}, {2, 2}},
          .expected = false,
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::isToeplitzMatrix(matrix);
    REQUIRE(expected == actual);
  }
}
