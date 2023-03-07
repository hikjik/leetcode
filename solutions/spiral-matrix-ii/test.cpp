#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> matrix{{1}};
    REQUIRE(matrix == Solution::generateMatrix(1));
  }
  {
    std::vector<std::vector<int>> matrix{{1, 2}, {4, 3}};
    REQUIRE(matrix == Solution::generateMatrix(2));
  }
  {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    REQUIRE(matrix == Solution::generateMatrix(3));
  }
}
