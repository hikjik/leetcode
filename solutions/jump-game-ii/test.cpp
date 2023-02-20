#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(2 == Solution::jump({2, 3, 1, 1, 4}));
  REQUIRE(2 == Solution::jump({2, 3, 0, 1, 4}));
}