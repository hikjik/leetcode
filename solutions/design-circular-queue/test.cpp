#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  int k = 3;
  auto my_circular_queue = MyCircularQueue(k);

  REQUIRE(true == my_circular_queue.enQueue(1));
  REQUIRE(true == my_circular_queue.enQueue(2));
  REQUIRE(true == my_circular_queue.enQueue(3));
  REQUIRE(false == my_circular_queue.enQueue(4));
  REQUIRE(3 == my_circular_queue.Rear());
  REQUIRE(true == my_circular_queue.isFull());
  REQUIRE(true == my_circular_queue.deQueue());
  REQUIRE(true == my_circular_queue.enQueue(4));
  REQUIRE(4 == my_circular_queue.Rear());
}
