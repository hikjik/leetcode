#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  MyStack stack;
  stack.push(1);
  stack.push(2);
  REQUIRE(2 == stack.top());
  REQUIRE(2 == stack.pop());
  REQUIRE_FALSE(stack.empty());
  REQUIRE(1 == stack.pop());
  REQUIRE(stack.empty());
}
