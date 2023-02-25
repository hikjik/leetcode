#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<char>> maze{
        {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    std::vector<int> entrance{1, 2};
    REQUIRE(1 == Solution::nearestExit(maze, entrance));
  }
  {
    std::vector<std::vector<char>> maze{
        {'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
    std::vector<int> entrance{1, 0};
    REQUIRE(2 == Solution::nearestExit(maze, entrance));
  }
  {
    std::vector<std::vector<char>> maze{{'.', '+'}};
    std::vector<int> entrance{0, 0};
    REQUIRE(-1 == Solution::nearestExit(maze, entrance));
  }
}
