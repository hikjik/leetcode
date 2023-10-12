#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto my_calendar_three = MyCalendarThree();

  REQUIRE(1 == my_calendar_three.book(10, 20));
  REQUIRE(1 == my_calendar_three.book(50, 60));
  REQUIRE(2 == my_calendar_three.book(10, 40));
  REQUIRE(3 == my_calendar_three.book(5, 15));
  REQUIRE(3 == my_calendar_three.book(5, 10));
  REQUIRE(3 == my_calendar_three.book(25, 55));
}
