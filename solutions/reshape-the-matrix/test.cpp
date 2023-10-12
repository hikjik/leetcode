#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat;
    int r;
    int c;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat{{1, 2}, {3, 4}},
          .r = 1,
          .c = 4,
          .expected{{1, 2, 3, 4}},
      },
      {
          .mat{{1, 2}, {3, 4}},
          .r = 2,
          .c = 4,
          .expected{{1, 2}, {3, 4}},
      },
  };

  for (const auto &[mat, r, c, expected] : test_cases) {
    const auto actual = Solution::matrixReshape(mat, r, c);
    REQUIRE(expected == actual);
  }
}
