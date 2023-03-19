#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(21 == Solution::nextGreaterElement(12));
  REQUIRE(-1 == Solution::nextGreaterElement(21));
}
