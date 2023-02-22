#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    REQUIRE(25 == Solution::diagonalSum(matrix));
  }
  {
    std::vector<std::vector<int>> matrix{
        {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    REQUIRE(8 == Solution::diagonalSum(matrix));
  }
  {
    std::vector<std::vector<int>> matrix{{5}};
    REQUIRE(5 == Solution::diagonalSum(matrix));
  }
}
