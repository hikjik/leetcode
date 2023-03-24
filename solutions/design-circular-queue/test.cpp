#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  MyCircularQueue q(3);
  REQUIRE(q.enQueue(1));
  REQUIRE(q.enQueue(2));
  REQUIRE(q.enQueue(3));
  REQUIRE_FALSE(q.enQueue(3));
  REQUIRE(3 == q.Rear());
  REQUIRE(q.isFull());
  REQUIRE(q.deQueue());
  REQUIRE(q.enQueue(4));
  REQUIRE(4 == q.Rear());
}
