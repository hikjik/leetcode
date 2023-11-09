#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  MinStack stack;

  stack.push(-2);
  stack.push(0);
  stack.push(-3);
  REQUIRE(-3 == stack.getMin());
  stack.pop();
  REQUIRE(0 == stack.top());
  REQUIRE(-2 == stack.getMin());
}
