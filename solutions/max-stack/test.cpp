#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto max_stack = MaxStack();

  max_stack.push(5);
  max_stack.push(1);
  max_stack.push(5);
  REQUIRE(5 == max_stack.top());
  REQUIRE(5 == max_stack.popMax());
  REQUIRE(1 == max_stack.top());
  REQUIRE(5 == max_stack.peekMax());
  REQUIRE(1 == max_stack.pop());
  REQUIRE(5 == max_stack.top());
}
