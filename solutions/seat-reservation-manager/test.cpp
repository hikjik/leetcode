#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Heap") {
  int n = 5;
  heap::SeatManager manager(n);

  REQUIRE(1 == manager.reserve());
  REQUIRE(2 == manager.reserve());
  manager.unreserve(2);
  REQUIRE(2 == manager.reserve());
  REQUIRE(3 == manager.reserve());
  REQUIRE(4 == manager.reserve());
  REQUIRE(5 == manager.reserve());
  manager.unreserve(5);
}

TEST_CASE("Set") {
  int n = 5;
  set::SeatManager manager(n);

  REQUIRE(1 == manager.reserve());
  REQUIRE(2 == manager.reserve());
  manager.unreserve(2);
  REQUIRE(2 == manager.reserve());
  REQUIRE(3 == manager.reserve());
  REQUIRE(4 == manager.reserve());
  REQUIRE(5 == manager.reserve());
  manager.unreserve(5);
}
