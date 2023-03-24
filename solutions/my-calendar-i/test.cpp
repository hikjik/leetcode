#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  MyCalendar calendar;
  REQUIRE(calendar.book(10, 20));
  REQUIRE_FALSE(calendar.book(15, 25));
  REQUIRE(calendar.book(20, 30));
}
