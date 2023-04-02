#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  ProductOfNumbers prod;
  prod.add(3);
  prod.add(0);
  prod.add(2);
  prod.add(5);
  prod.add(4);
  REQUIRE(20 == prod.getProduct(2));
  REQUIRE(40 == prod.getProduct(3));
  REQUIRE(0 == prod.getProduct(4));
  prod.add(8);
  REQUIRE(32 == prod.getProduct(2));
}
