#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(964176192 == Solution::reverseBits(43261596));
  REQUIRE(3221225471 == Solution::reverseBits(4294967293));
}
