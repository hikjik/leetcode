#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<char>> board{{'X', 'X', 'X', 'X'},
                                         {'X', 'O', 'O', 'X'},
                                         {'X', 'X', 'O', 'X'},
                                         {'X', 'O', 'X', 'X'}};
    std::vector<std::vector<char>> expected{{'X', 'X', 'X', 'X'},
                                            {'X', 'X', 'X', 'X'},
                                            {'X', 'X', 'X', 'X'},
                                            {'X', 'O', 'X', 'X'}};
    Solution::solve(board);
    REQUIRE(expected == board);
  }
  {
    std::vector<std::vector<char>> board{{'X'}};
    std::vector<std::vector<char>> expected{{'X'}};
    Solution::solve(board);
    REQUIRE(expected == board);
  }
}
