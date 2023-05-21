#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> board = {
        {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
    REQUIRE(4 == Solution::snakesAndLadders(board));
  }
  {
    std::vector<std::vector<int>> board = {{-1, -1}, {-1, 3}};
    REQUIRE(1 == Solution::snakesAndLadders(board));
  }
  {
    std::vector<std::vector<int>> board = {
        {-1, -1, -1}, {-1, 9, 8}, {-1, 8, 9}};
    REQUIRE(1 == Solution::snakesAndLadders(board));
  }
}
