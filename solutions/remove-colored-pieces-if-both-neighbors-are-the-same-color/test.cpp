#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::winnerOfGame("AAABABB"));
  REQUIRE_FALSE(Solution::winnerOfGame("AA"));
  REQUIRE_FALSE(Solution::winnerOfGame("ABBBBBBBAAA"));
}
