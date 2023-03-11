#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    Matrix<int> mat{{0, 1}, {1, 0}};
    Matrix<int> target{{1, 0}, {0, 1}};
    REQUIRE(Solution::findRotation(mat, target));
  }
  {
    Matrix<int> mat{{0, 1}, {1, 1}};
    Matrix<int> target{{1, 0}, {0, 1}};
    REQUIRE_FALSE(Solution::findRotation(mat, target));
  }
  {
    Matrix<int> mat{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    Matrix<int> target{{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    REQUIRE(Solution::findRotation(mat, target));
  }
}
