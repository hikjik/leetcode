#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

TEST_CASE("Simple") {
  struct TestCase {
    List list;
    int insertVal;
    List expected;
  };

  std::vector<TestCase> test_cases{
      {
          .list = {3, 4, 1},
          .insertVal = 2,
          .expected = {3, 4, 1, 2},
      },
      {
          .list = {},
          .insertVal = 1,
          .expected = {1},
      },
      {
          .list = {1},
          .insertVal = 0,
          .expected = {1, 0},
      },
      {
          .list = {3, 3, 3},
          .insertVal = 0,
          .expected = {3, 0, 3, 3},
      },
      {
          .list = {3, 10, 5},
          .insertVal = 2,
          .expected = {3, 10, 2, 5},
      },
      {
          .list = {3, 10, 5},
          .insertVal = 15,
          .expected = {3, 10, 15, 5},
      },
  };

  for (const auto &[list, insertVal, expected] : test_cases) {
    auto *head = Copy(list);
    if (head) {
      auto *tail = head;
      while (tail->next) {
        tail = tail->next;
      }
      tail->next = head;
    }

    auto *newHead = Solution::insert(head, insertVal);
    auto *newTail = newHead;
    while (newTail->next != newHead) {
      newTail = newTail->next;
    }
    newTail->next = nullptr;

    REQUIRE(expected == List(newHead));
  }
}
