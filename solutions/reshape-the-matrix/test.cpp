#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    Matrix<int> mat{{1, 2}, {3, 4}};
    Matrix<int> expected{{1, 2, 3, 4}};
    REQUIRE(expected == Solution::matrixReshape(mat, 1, 4));
  }
  {
    Matrix<int> mat{{1, 2}, {3, 4}};
    Matrix<int> expected{{1, 2}, {3, 4}};
    REQUIRE(expected == Solution::matrixReshape(mat, 2, 4));
  }
}
