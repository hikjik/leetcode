#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto list = MyLinkedList();
  list.addAtHead(1);
  list.addAtTail(3);
  list.addAtIndex(1, 2);
  REQUIRE(1 == list.get(0));
  REQUIRE(2 == list.get(1));
  REQUIRE(3 == list.get(2));
  list.deleteAtIndex(1);
  REQUIRE(1 == list.get(0));
  REQUIRE(3 == list.get(1));
  REQUIRE(-1 == list.get(2));
  list.deleteAtIndex(0);
  REQUIRE(3 == list.get(0));
  REQUIRE(-1 == list.get(1));
  list.deleteAtIndex(0);
  REQUIRE(-1 == list.get(0));
  list.addAtIndex(0, 5);
  REQUIRE(5 == list.get(0));
  REQUIRE(-1 == list.get(1));
}
