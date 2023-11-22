#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  AllOne all_one;

  all_one.inc("hello");
  all_one.inc("hello");
  REQUIRE("hello" == all_one.getMaxKey());
  REQUIRE("hello" == all_one.getMinKey());
  all_one.inc("leet");
  REQUIRE("hello" == all_one.getMaxKey());
  REQUIRE("leet" == all_one.getMinKey());
  all_one.dec("leet");
  REQUIRE("hello" == all_one.getMaxKey());
  REQUIRE("hello" == all_one.getMinKey());
  all_one.dec("hello");
  REQUIRE("hello" == all_one.getMaxKey());
  REQUIRE("hello" == all_one.getMinKey());
  all_one.dec("hello");
  REQUIRE("" == all_one.getMaxKey());
  REQUIRE("" == all_one.getMinKey());
}
