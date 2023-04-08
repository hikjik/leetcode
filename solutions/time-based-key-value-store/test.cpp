#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    TimeMap map;

    map.set("foo", "bar", 1);
    REQUIRE("bar" == map.get("foo", 1));
    REQUIRE("bar" == map.get("foo", 3));

    map.set("foo", "bar2", 4);
    REQUIRE("bar2" == map.get("foo", 4));
    REQUIRE("bar2" == map.get("foo", 5));
  }
  {
    TimeMap map;

    map.set("love", "high", 10);
    map.set("love", "low", 20);

    REQUIRE("" == map.get("love", 5));
    REQUIRE("high" == map.get("love", 10));
    REQUIRE("high" == map.get("love", 15));
    REQUIRE("low" == map.get("love", 20));
    REQUIRE("low" == map.get("love", 25));
  }
}
