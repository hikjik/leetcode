#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> matrix;
    int target;
    int expected;
  };

  std::vector<TestCase> test_cases{
      {
          .matrix{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}},
          .target = 0,
          .expected = 4,
      },
      {
          .matrix{{1, -1}, {-1, 1}},
          .target = 0,
          .expected = 5,
      },
      {
          .matrix{{904}},
          .target = 0,
          .expected = 0,
      },
  };

  for (const auto &[matrix, target, expected] : test_cases) {
    const auto actual = Solution::numSubmatrixSumTarget(matrix, target);
    REQUIRE(expected == actual);
  }
}
