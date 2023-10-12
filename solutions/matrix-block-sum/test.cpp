#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int k;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .k = 1,
          .expected{{12, 21, 16}, {27, 45, 33}, {24, 39, 28}},
      },
      {
          .mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          .k = 2,
          .expected{{45, 45, 45}, {45, 45, 45}, {45, 45, 45}},
      },
  };

  for (const auto &[mat, k, expected] : test_cases) {
    const auto actual = Solution::matrixBlockSum(mat, k);
    REQUIRE(expected == actual);
  }
}
