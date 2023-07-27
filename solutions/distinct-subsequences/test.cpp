#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(3 == Solution::numDistinct("rabbbit", "rabbit"));
  REQUIRE(5 == Solution::numDistinct("babgbag", "bag"));
}
