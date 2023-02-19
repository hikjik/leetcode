#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::canJump({2, 3, 1, 1, 4}));
  REQUIRE_FALSE(Solution::canJump({3, 2, 1, 0, 4}));
  REQUIRE(Solution::canJump({0}));
  REQUIRE(Solution::canJump({2, 0, 0}));
}