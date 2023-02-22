#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::arrangeCoins(1));
  REQUIRE(1 == Solution::arrangeCoins(2));
  REQUIRE(2 == Solution::arrangeCoins(3));
  REQUIRE(2 == Solution::arrangeCoins(4));
  REQUIRE(2 == Solution::arrangeCoins(5));
  REQUIRE(3 == Solution::arrangeCoins(6));
  REQUIRE(3 == Solution::arrangeCoins(7));
  REQUIRE(3 == Solution::arrangeCoins(8));
}
