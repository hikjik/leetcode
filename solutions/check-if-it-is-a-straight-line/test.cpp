#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(Solution::checkStraightLine(
      {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}}));
  REQUIRE_FALSE(Solution::checkStraightLine(
      {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}}));
  REQUIRE(Solution::checkStraightLine({{0, 0}, {0, 1}, {0, -1}}));
}
