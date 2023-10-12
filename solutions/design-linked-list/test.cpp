#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  auto my_linked_list = MyLinkedList();

  my_linked_list.addAtHead(1);
  my_linked_list.addAtTail(3);
  my_linked_list.addAtIndex(1, 2);
  REQUIRE(2 == my_linked_list.get(1));
  my_linked_list.deleteAtIndex(1);
  REQUIRE(3 == my_linked_list.get(1));
}
