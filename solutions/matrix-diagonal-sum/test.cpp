#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .expected = 25,
      },
      {
          .mat{{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}},
          .expected = 8,
      },
      {
          .mat{{5}},
          .expected = 5,
      },
  };

  for (const auto &[mat, expected] : test_cases) {
    const auto actual = Solution::diagonalSum(mat);
    REQUIRE(expected == actual);
  }
}
