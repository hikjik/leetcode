#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int maxSize = 3;
    auto custom_stack = CustomStack(maxSize);

    custom_stack.push(1);
    custom_stack.push(2);
    REQUIRE(2 == custom_stack.pop());
    custom_stack.push(2);
    custom_stack.push(3);
    custom_stack.push(4);
    custom_stack.increment(5, 100);
    custom_stack.increment(2, 100);
    REQUIRE(103 == custom_stack.pop());
    REQUIRE(202 == custom_stack.pop());
    REQUIRE(201 == custom_stack.pop());
    REQUIRE(-1 == custom_stack.pop());
  }
}
