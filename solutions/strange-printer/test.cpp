#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::strangePrinter("aaabbb"));
  REQUIRE(2 == Solution::strangePrinter("aba"));
}
