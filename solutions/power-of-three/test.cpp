#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::isPowerOfThree(27));
  REQUIRE_FALSE(Solution::isPowerOfThree(0));
  REQUIRE_FALSE(Solution::isPowerOfThree(-1));
}
