#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> board{
        {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution::gameOfLife(board);
    std::vector<std::vector<int>> expected{
        {0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};
    REQUIRE(expected == board);
  }
  {
    std::vector<std::vector<int>> board{{1, 1}, {1, 0}};
    Solution::gameOfLife(board);
    std::vector<std::vector<int>> expected{{1, 1}, {1, 1}};
    REQUIRE(expected == board);
  }
}
