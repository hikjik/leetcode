#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    double x = 2.00000;
    int n = 10;
    REQUIRE(1024.00000 == Approx(Solution::myPow(x, n)));
  }
  {
    double x = 2.10000;
    int n = 3;
    REQUIRE(9.26100 == Approx(Solution::myPow(x, n)));
  }
  {
    double x = 2.00000;
    int n = -2;
    REQUIRE(0.25000 == Approx(Solution::myPow(x, n)));
  }
}
