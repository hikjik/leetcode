#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  std::vector<std::vector<int>> matrix{{1, 4, 7, 11, 15},
                                       {2, 5, 8, 12, 19},
                                       {3, 6, 9, 16, 22},
                                       {10, 13, 14, 17, 24},
                                       {18, 21, 23, 26, 30}};
  REQUIRE(Solution::searchMatrix(matrix, 5));
  REQUIRE_FALSE(Solution::searchMatrix(matrix, 20));
}
