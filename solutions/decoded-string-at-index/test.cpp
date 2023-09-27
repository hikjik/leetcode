#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("o" == Solution::decodeAtIndex("leet2code3", 10));
  REQUIRE("h" == Solution::decodeAtIndex("ha22", 5));
  REQUIRE("a" == Solution::decodeAtIndex("a2345678999999999999999", 1));
}
