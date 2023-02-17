#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<ChessBoard> expected{{".Q..", "...Q", "Q...", "..Q."},
                                     {"..Q.", "Q...", "...Q", ".Q.."}};
    REQUIRE(expected == Solution::solveNQueens(4));
  }
  {
    std::vector<ChessBoard> expected{{"Q"}};
    REQUIRE(expected == Solution::solveNQueens(1));
  }
}
