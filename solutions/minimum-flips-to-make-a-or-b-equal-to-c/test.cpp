#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int a = 2, b = 6, c = 5;
    REQUIRE(3 == Solution::minFlips(a, b, c));
  }
  {
    int a = 4, b = 2, c = 7;
    REQUIRE(1 == Solution::minFlips(a, b, c));
  }
  {
    int a = 1, b = 2, c = 3;
    REQUIRE(0 == Solution::minFlips(a, b, c));
  }
}
