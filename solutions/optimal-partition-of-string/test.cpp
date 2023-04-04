#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(4 == Solution::partitionString("abacaba"));
  REQUIRE(6 == Solution::partitionString("ssssss"));
}
