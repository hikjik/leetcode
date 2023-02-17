#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  REQUIRE(0 == Solution::fib(0));
  REQUIRE(1 == Solution::fib(1));
  REQUIRE(1 == Solution::fib(2));
  REQUIRE(2 == Solution::fib(3));
  REQUIRE(3 == Solution::fib(4));
  REQUIRE(5 == Solution::fib(5));
}

TEST_CASE("Big") {
  REQUIRE(832040 == Solution::fib(30));
  REQUIRE(514229 == Solution::fib(29));
}
