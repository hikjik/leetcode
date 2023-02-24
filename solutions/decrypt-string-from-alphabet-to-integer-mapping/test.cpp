#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("jkab" == Solution::freqAlphabets("10#11#12"));
  REQUIRE("acz" == Solution::freqAlphabets("1326#"));
}
