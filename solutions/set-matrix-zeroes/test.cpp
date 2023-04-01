#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution::setZeroes(matrix);
    std::vector<std::vector<int>> expected{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    REQUIRE(expected == matrix);
  }
  {
    std::vector<std::vector<int>> matrix{
        {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution::setZeroes(matrix);
    std::vector<std::vector<int>> expected{
        {0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    REQUIRE(expected == matrix);
  }
}
