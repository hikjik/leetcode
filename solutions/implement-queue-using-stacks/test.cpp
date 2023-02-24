#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto queue = new MyQueue();
  queue->push(1);
  queue->push(2);
  REQUIRE(1 == queue->peek());
  REQUIRE(1 == queue->pop());
  REQUIRE_FALSE(queue->empty());
  REQUIRE(2 == queue->peek());
  REQUIRE(2 == queue->pop());
  REQUIRE(queue->empty());
}
