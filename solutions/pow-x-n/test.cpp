#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    double x = 2.00000;
    int n = 10;
    double expected = 1024.00000;
    REQUIRE(expected == Solution::myPow(x, n));
  }
  {
    double x = 2.10000;
    int n = 3;
    double expected = 9.26100;
    REQUIRE(expected == Solution::myPow(x, n));
  }
  {
    double x = 2.00000;
    int n = -2;
    double expected = 0.25000;
    REQUIRE(expected == Solution::myPow(x, n));
  }
}
