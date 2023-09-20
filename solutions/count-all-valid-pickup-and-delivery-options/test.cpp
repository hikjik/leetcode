#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::countOrders(1));
  REQUIRE(6 == Solution::countOrders(2));
  REQUIRE(90 == Solution::countOrders(3));
}
