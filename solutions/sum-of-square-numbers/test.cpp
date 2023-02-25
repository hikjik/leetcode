#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::judgeSquareSum(5));
  REQUIRE_FALSE(Solution::judgeSquareSum(3));
  REQUIRE(Solution::judgeSquareSum(0));
  REQUIRE_FALSE(Solution::judgeSquareSum(2147482647));
}
