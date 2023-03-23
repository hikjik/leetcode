#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  SeatManager manager(5);
  REQUIRE(1 == manager.reserve());
  REQUIRE(2 == manager.reserve());
  manager.unreserve(2);
  REQUIRE(2 == manager.reserve());
  REQUIRE(3 == manager.reserve());
  REQUIRE(4 == manager.reserve());
  REQUIRE(5 == manager.reserve());
  manager.unreserve(5);
}
