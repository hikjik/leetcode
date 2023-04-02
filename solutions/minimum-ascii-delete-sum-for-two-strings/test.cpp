#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(231 == Solution::minimumDeleteSum("sea", "eat"));
  REQUIRE(403 == Solution::minimumDeleteSum("delete", "leet"));
}
