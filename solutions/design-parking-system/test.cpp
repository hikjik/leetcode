#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int big = 1;
  int medium = 1;
  int small = 0;
  auto parking_system = ParkingSystem(big, medium, small);

  REQUIRE(true == parking_system.addCar(1));
  REQUIRE(true == parking_system.addCar(2));
  REQUIRE(false == parking_system.addCar(3));
  REQUIRE(false == parking_system.addCar(1));
}
