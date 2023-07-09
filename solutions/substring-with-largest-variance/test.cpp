#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::largestVariance("aababbb"));
  REQUIRE(0 == Solution::largestVariance("abcde"));
}
