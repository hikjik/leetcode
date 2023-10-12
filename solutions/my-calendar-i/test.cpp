#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto my_calendar = MyCalendar();

  REQUIRE(true == my_calendar.book(10, 20));
  REQUIRE(false == my_calendar.book(15, 25));
  REQUIRE(true == my_calendar.book(20, 30));
}
