#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  FreqStack stack;
  stack.push(5);
  stack.push(7);
  stack.push(5);
  stack.push(7);
  stack.push(4);
  stack.push(5);

  REQUIRE(5 == stack.pop());
  REQUIRE(7 == stack.pop());
  REQUIRE(5 == stack.pop());
  REQUIRE(4 == stack.pop());
  REQUIRE(7 == stack.pop());
  REQUIRE(5 == stack.pop());
}
