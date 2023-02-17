#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::totalNQueens(1));
  REQUIRE(2 == Solution::totalNQueens(4));
}
