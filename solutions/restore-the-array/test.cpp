#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(1 == Solution::numberOfArrays("1000", 10000));
  REQUIRE(0 == Solution::numberOfArrays("1000", 10));
  REQUIRE(8 == Solution::numberOfArrays("1317", 2000));
  REQUIRE(1 == Solution::numberOfArrays("2020", 30));
}
