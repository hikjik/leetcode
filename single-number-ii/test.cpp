#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  { REQUIRE(3 == Solution::singleNumber({2, 2, 3, 2})); }
  { REQUIRE(99 == Solution::singleNumber({0, 1, 0, 1, 0, 1, 99})); }
}
