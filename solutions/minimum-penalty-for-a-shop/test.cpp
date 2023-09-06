#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::bestClosingTime("YYNY"));
  REQUIRE(0 == Solution::bestClosingTime("NNNNN"));
  REQUIRE(4 == Solution::bestClosingTime("YYYY"));
}
