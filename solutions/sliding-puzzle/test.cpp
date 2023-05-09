#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> board{{1, 2, 3}, {4, 0, 5}};
    REQUIRE(1 == Solution::slidingPuzzle(board));
  }
  {
    std::vector<std::vector<int>> board{{1, 2, 3}, {5, 4, 0}};
    REQUIRE(-1 == Solution::slidingPuzzle(board));
  }

  {
    std::vector<std::vector<int>> board{{4, 1, 2}, {5, 0, 3}};
    REQUIRE(5 == Solution::slidingPuzzle(board));
  }
}
