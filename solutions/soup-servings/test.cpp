#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0.62500 == Solution().soupServings(50));
  REQUIRE(0.71875 == Solution().soupServings(100));
}
