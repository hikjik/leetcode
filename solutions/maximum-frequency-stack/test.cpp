#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto freq_stack = FreqStack();

  freq_stack.push(5);
  freq_stack.push(7);
  freq_stack.push(5);
  freq_stack.push(7);
  freq_stack.push(4);
  freq_stack.push(5);
  REQUIRE(5 == freq_stack.pop());
  REQUIRE(7 == freq_stack.pop());
  REQUIRE(5 == freq_stack.pop());
  REQUIRE(4 == freq_stack.pop());
}
