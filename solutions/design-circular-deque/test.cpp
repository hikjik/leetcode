#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int k = 3;
  auto deque = MyCircularDeque(k);

  REQUIRE(deque.insertLast(1));
  REQUIRE(deque.insertLast(2));
  REQUIRE(deque.insertFront(3));
  REQUIRE_FALSE(deque.insertFront(4));
  REQUIRE(2 == deque.getRear());
  REQUIRE(deque.isFull());
  REQUIRE(deque.deleteLast());
  REQUIRE(deque.insertFront(4));
  REQUIRE(4 == deque.getFront());
}
