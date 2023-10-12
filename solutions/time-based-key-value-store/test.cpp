#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto time_map = TimeMap();

  time_map.set("foo", "bar", 1);
  REQUIRE("bar" == time_map.get("foo", 1));
  REQUIRE("bar" == time_map.get("foo", 3));
  time_map.set("foo", "bar2", 4);
  REQUIRE("bar2" == time_map.get("foo", 4));
  REQUIRE("bar2" == time_map.get("foo", 5));
}
