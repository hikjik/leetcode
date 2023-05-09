#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::minimumOneBitOperations(3));
  REQUIRE(4 == Solution::minimumOneBitOperations(6));
}
