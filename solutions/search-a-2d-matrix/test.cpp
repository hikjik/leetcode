#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    Matrix<int> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    REQUIRE(Solution::searchMatrix(matrix, 3));
  }
  {
    Matrix<int> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    REQUIRE_FALSE(Solution::searchMatrix(matrix, 13));
  }
  {
    Matrix<int> matrix{{1, 1}};
    REQUIRE_FALSE(Solution::searchMatrix(matrix, 0));
  }
  {
    Matrix<int> matrix{{1}, {3}};
    REQUIRE_FALSE(Solution::searchMatrix(matrix, 0));
  }
}
