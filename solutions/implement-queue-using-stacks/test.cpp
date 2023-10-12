#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto my_queue = MyQueue();

  my_queue.push(1);
  my_queue.push(2);
  REQUIRE(1 == my_queue.peek());
  REQUIRE(1 == my_queue.pop());
  REQUIRE(false == my_queue.empty());
}
