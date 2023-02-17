#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(6 == Solution::countDigitOne(13));
  REQUIRE(0 == Solution::countDigitOne(0));
}

TEST_CASE("Big") { REQUIRE(900000001 == Solution::countDigitOne(1e9)); }
