#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("213" == Solution::getPermutation(3, 3));
  REQUIRE("2314" == Solution::getPermutation(4, 9));
  REQUIRE("123" == Solution::getPermutation(3, 1));
}
