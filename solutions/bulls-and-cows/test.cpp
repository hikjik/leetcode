#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("1A3B" == Solution::getHint("1807", "7810"));
  REQUIRE("1A1B" == Solution::getHint("1123", "0111"));
}
