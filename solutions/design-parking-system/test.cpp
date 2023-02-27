#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  ParkingSystem *obj = new ParkingSystem(1, 1, 0);
  REQUIRE(obj->addCar(1));
  REQUIRE(obj->addCar(2));
  REQUIRE_FALSE(obj->addCar(3));
  REQUIRE_FALSE(obj->addCar(1));
  REQUIRE_FALSE(obj->addCar(2));
  REQUIRE_FALSE(obj->addCar(3));
}
