#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  MyCalendarThree calendar;
  REQUIRE(1 == calendar.book(10, 20));
  REQUIRE(1 == calendar.book(50, 60));
  REQUIRE(2 == calendar.book(10, 40));
  REQUIRE(3 == calendar.book(5, 15));
  REQUIRE(3 == calendar.book(5, 10));
  REQUIRE(3 == calendar.book(25, 55));
}
