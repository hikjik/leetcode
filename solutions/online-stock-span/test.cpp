#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto stock_spanner = StockSpanner();

  REQUIRE(1 == stock_spanner.next(100));
  REQUIRE(1 == stock_spanner.next(80));
  REQUIRE(1 == stock_spanner.next(60));
  REQUIRE(2 == stock_spanner.next(70));
  REQUIRE(1 == stock_spanner.next(60));
  REQUIRE(4 == stock_spanner.next(75));
  REQUIRE(6 == stock_spanner.next(85));
}
