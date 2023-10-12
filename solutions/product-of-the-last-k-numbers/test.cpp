#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto product_of_numbers = ProductOfNumbers();

  product_of_numbers.add(3);
  product_of_numbers.add(0);
  product_of_numbers.add(2);
  product_of_numbers.add(5);
  product_of_numbers.add(4);
  REQUIRE(20 == product_of_numbers.getProduct(2));
  REQUIRE(40 == product_of_numbers.getProduct(3));
  REQUIRE(0 == product_of_numbers.getProduct(4));
  product_of_numbers.add(8);
  REQUIRE(32 == product_of_numbers.getProduct(2));
}
