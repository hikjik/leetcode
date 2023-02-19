#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(6 == Solution::deleteAndEarn({3, 4, 2}));
  REQUIRE(9 == Solution::deleteAndEarn({2, 2, 3, 3, 3, 4}));
}