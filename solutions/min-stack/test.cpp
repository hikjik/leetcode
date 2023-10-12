#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto min_stack = MinStack();

  min_stack.push(-2);
  min_stack.push(0);
  min_stack.push(-3);
  REQUIRE(-3 == min_stack.getMin());
  min_stack.pop();
  REQUIRE(0 == min_stack.top());
  REQUIRE(-2 == min_stack.getMin());
}
