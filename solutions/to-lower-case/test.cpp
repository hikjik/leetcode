#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("hello" == Solution::toLowerCase("Hello"));
  REQUIRE("here" == Solution::toLowerCase("here"));
  REQUIRE("lovely" == Solution::toLowerCase("LOVELY"));
}
