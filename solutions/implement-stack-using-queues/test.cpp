#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto my_stack = MyStack();

  my_stack.push(1);
  my_stack.push(2);
  REQUIRE(2 == my_stack.top());
  REQUIRE(2 == my_stack.pop());
  REQUIRE(false == my_stack.empty());
}
