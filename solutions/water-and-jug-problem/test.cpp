#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::canMeasureWater(3, 5, 4));
  REQUIRE_FALSE(Solution::canMeasureWater(2, 6, 5));
  REQUIRE(Solution::canMeasureWater(1, 2, 3));
  REQUIRE(Solution::canMeasureWater(0, 0, 0));
}
