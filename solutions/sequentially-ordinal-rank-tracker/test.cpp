#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto tracker = SORTracker();

  tracker.add("bradford", 2);
  tracker.add("branford", 3);
  REQUIRE("branford" == tracker.get());
  tracker.add("alps", 2);
  REQUIRE("alps" == tracker.get());
  tracker.add("orland", 2);
  REQUIRE("bradford" == tracker.get());
  tracker.add("orlando", 3);
  REQUIRE("bradford" == tracker.get());
  tracker.add("alpine", 2);
  REQUIRE("bradford" == tracker.get());
  REQUIRE("orland" == tracker.get());
}
