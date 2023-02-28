#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isPowerOfTwo(1));
  REQUIRE(Solution::isPowerOfTwo(16));
  REQUIRE_FALSE(Solution::isPowerOfTwo(3));
}
