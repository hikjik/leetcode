#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .expected{{1, 4, 7}, {2, 5, 8}, {3, 6, 9}},
      },
      {
          .matrix{{1, 2, 3}, {4, 5, 6}},
          .expected{{1, 4}, {2, 5}, {3, 6}},
      },
  };

  for (const auto &[matrix, expected] : test_cases) {
    const auto actual = Solution::transpose(matrix);
    REQUIRE(expected == actual);
  }
}
