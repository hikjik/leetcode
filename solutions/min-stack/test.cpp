#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  REQUIRE(-3 == obj->getMin());
  obj->pop();
  REQUIRE(0 == obj->top());
  REQUIRE(-2 == obj->getMin());
}
