#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("lecoe" == Solution::removeStars("leet**cod*e"));
  REQUIRE("" == Solution::removeStars("erase*****"));
}
