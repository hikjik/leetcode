#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    REQUIRE(15 == Solution::subtractProductAndSum(234));
    REQUIRE(21 == Solution::subtractProductAndSum(4421));
  }
}
