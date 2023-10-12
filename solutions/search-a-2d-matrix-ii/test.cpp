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
          .matrix{{1, 4, 7, 11, 15},
                  {2, 5, 8, 12, 19},
                  {3, 6, 9, 16, 22},
                  {10, 13, 14, 17, 24},
                  {18, 21, 23, 26, 30}},
          .target = 5,
          .expected = true,
      },
      {
          .matrix{{1, 4, 7, 11, 15},
                  {2, 5, 8, 12, 19},
                  {3, 6, 9, 16, 22},
                  {10, 13, 14, 17, 24},
                  {18, 21, 23, 26, 30}},
          .target = 20,
          .expected = false,
      },
  };

  for (const auto &[matrix, target, expected] : test_cases) {
    const auto actual = Solution::searchMatrix(matrix, target);
    REQUIRE(expected == actual);
  }
}
