#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("134" == Solution::addStrings("11", "123"));
  REQUIRE("533" == Solution::addStrings("456", "77"));
  REQUIRE("0" == Solution::addStrings("0", "0"));
  REQUIRE("100" == Solution::addStrings("50", "50"));
}
