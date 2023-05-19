#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  StockSpanner stockSpanner;
  REQUIRE(1 == stockSpanner.next(100));
  REQUIRE(1 == stockSpanner.next(80));
  REQUIRE(1 == stockSpanner.next(60));
  REQUIRE(2 == stockSpanner.next(70));
  REQUIRE(1 == stockSpanner.next(60));
  REQUIRE(4 == stockSpanner.next(75));
  REQUIRE(6 == stockSpanner.next(85));
}
