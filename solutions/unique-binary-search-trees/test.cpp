#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::numTrees(1));
  REQUIRE(2 == Solution::numTrees(2));
  REQUIRE(5 == Solution::numTrees(3));
}
