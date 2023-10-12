#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int n = 5;
  auto seat_manager = SeatManager(n);

  REQUIRE(1 == seat_manager.reserve());
  REQUIRE(2 == seat_manager.reserve());
  seat_manager.unreserve(2);
  REQUIRE(2 == seat_manager.reserve());
  REQUIRE(3 == seat_manager.reserve());
  REQUIRE(4 == seat_manager.reserve());
  REQUIRE(5 == seat_manager.reserve());
  seat_manager.unreserve(5);
}
