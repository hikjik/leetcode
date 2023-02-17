#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::hammingWeight(11));
  REQUIRE(1 == Solution::hammingWeight(128));
  REQUIRE(31 == Solution::hammingWeight(4294967293));
}
