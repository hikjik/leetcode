#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE("acb" == Solution::orderlyQueue("cba", 1));
  REQUIRE("aaabc" == Solution::orderlyQueue("baaca", 3));
}
