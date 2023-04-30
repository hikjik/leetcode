#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  MyCalendarTwo calendar;
  REQUIRE(calendar.book(10, 20));
  REQUIRE(calendar.book(50, 60));
  REQUIRE(calendar.book(10, 40));
  REQUIRE_FALSE(calendar.book(5, 15));
  REQUIRE(calendar.book(5, 10));
  REQUIRE(calendar.book(25, 55));
}
