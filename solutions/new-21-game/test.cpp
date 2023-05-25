#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 10, k = 1, maxPts = 10;
    REQUIRE(1.00000 == Approx(Solution::new21Game(n, k, maxPts)));
  }
  {
    int n = 6, k = 1, maxPts = 10;
    REQUIRE(0.60000 == Approx(Solution::new21Game(n, k, maxPts)));
  }
  {
    int n = 21, k = 17, maxPts = 10;
    REQUIRE(0.73278 == Approx(Solution::new21Game(n, k, maxPts)));
  }
}
