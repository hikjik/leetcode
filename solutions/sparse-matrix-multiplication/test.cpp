#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> mat1;
    std::vector<std::vector<int>> mat2;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .mat1{{1, 0, 0}, {-1, 0, 3}},
          .mat2{{7, 0, 0}, {0, 0, 0}, {0, 0, 1}},
          .expected{{7, 0, 0}, {-7, 0, 3}},
      },
      {
          .mat1{{0}},
          .mat2{{0}},
          .expected{{0}},
      },
  };

  SECTION("Naive") {
    for (const auto &[mat1, mat2, expected] : test_cases) {
      const auto actual = naive::Solution::multiply(mat1, mat2);
      REQUIRE(expected == actual);
    }
  }

  SECTION("Optimized") {
    for (const auto &[mat1, mat2, expected] : test_cases) {
      const auto actual = opt::Solution::multiply(mat1, mat2);
      REQUIRE(expected == actual);
    }
  }
}
