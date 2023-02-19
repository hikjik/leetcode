#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::canMakeArithmeticProgression({3, 5, 1}));
  REQUIRE_FALSE(Solution::canMakeArithmeticProgression({1, 2, 4}));
}
