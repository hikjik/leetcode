#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  { REQUIRE("100" == Solution::addBinary("11", "1")); }
  { REQUIRE("10101" == Solution::addBinary("1010", "1011")); }
}
