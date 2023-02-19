#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::arraySign({-1, -2, -3, -4, 3, 2, 1}));
  REQUIRE(-1 == Solution::arraySign({-1, 1, -1, 1, -1}));
  REQUIRE(0 == Solution::arraySign({1, 5, 0, 2, -3}));
}
