#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::findTheWinner(5, 2));
  REQUIRE(1 == Solution::findTheWinner(6, 5));
}
