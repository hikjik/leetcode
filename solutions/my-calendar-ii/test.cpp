#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto my_calendar_two = MyCalendarTwo();

  REQUIRE(true == my_calendar_two.book(10, 20));
  REQUIRE(true == my_calendar_two.book(50, 60));
  REQUIRE(true == my_calendar_two.book(10, 40));
  REQUIRE(false == my_calendar_two.book(5, 15));
  REQUIRE(true == my_calendar_two.book(5, 10));
  REQUIRE(true == my_calendar_two.book(25, 55));
}
