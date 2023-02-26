#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int m = 3, n = 7;
    REQUIRE(28 == Solution::uniquePaths(m, n));
  }
  {
    int m = 3, n = 2;
    REQUIRE(3 == Solution::uniquePaths(m, n));
  }
}
