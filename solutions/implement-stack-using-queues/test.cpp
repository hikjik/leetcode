#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("One Queue") {
  one_queue::MyStack stack;

  stack.push(1);
  stack.push(2);
  REQUIRE(2 == stack.top());
  REQUIRE(2 == stack.pop());
  REQUIRE(false == stack.empty());
}

TEST_CASE("Two Queue") {
  two_queue::MyStack stack;

  stack.push(1);
  stack.push(2);
  REQUIRE(2 == stack.top());
  REQUIRE(2 == stack.pop());
  REQUIRE(false == stack.empty());
}
