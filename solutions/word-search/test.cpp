#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<char>> board{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    REQUIRE(Solution::exist(board, "ABCCED"));
    REQUIRE(Solution::exist(board, "SEE"));
    REQUIRE_FALSE(Solution::exist(board, "ABCB"));
  }
}
