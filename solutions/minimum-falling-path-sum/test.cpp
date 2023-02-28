#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> matrix{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    REQUIRE(13 == Solution::minFallingPathSum(matrix));
  }
  {
    std::vector<std::vector<int>> matrix{{-19, 57}, {-40, -5}};
    REQUIRE(-59 == Solution::minFallingPathSum(matrix));
  }
}
