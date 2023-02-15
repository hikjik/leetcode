#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  { REQUIRE(1 == Solution::singleNumber({2, 2, 1})); }
  { REQUIRE(4 == Solution::singleNumber({4, 1, 2, 1, 2})); }
  { REQUIRE(1 == Solution::singleNumber({1})); }
}
