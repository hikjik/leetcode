#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    int target;
    bool expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}},
          .target = 3,
          .expected = true,
      },
      {
          .matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}},
          .target = 13,
          .expected = false,
      },
  };

  for (const auto &[matrix, target, expected] : test_cases) {
    const auto actual = Solution::searchMatrix(matrix, target);
    REQUIRE(expected == actual);
  }
}
