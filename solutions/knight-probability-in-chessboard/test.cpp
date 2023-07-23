#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3, k = 2, row = 0, column = 0;
    REQUIRE(0.06250 == Solution::knightProbability(n, k, row, column));
  }
  {
    int n = 1, k = 0, row = 0, column = 0;
    REQUIRE(1.00000 == Solution::knightProbability(n, k, row, column));
  }
}
