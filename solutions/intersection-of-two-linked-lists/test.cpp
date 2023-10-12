#include <catch.hpp>

#include <solution.hpp>

#include <list_node.h>

ListNode *Link(ListNode *head, ListNode *tail) {
  if (!head) {
    return tail;
  }

  auto node = head;
  while (node->next) {
    node = node->next;
  }
  node->next = tail;

  return head;
}

void Unlink(ListNode *head, ListNode *tail) {
  if (head == tail) {
    return;
  }

  auto node = head;
  while (node->next != tail) {
    node = node->next;
  }
  node->next = nullptr;
}

TEST_CASE("Simple") {
  struct TestCase {
    List listA;
    List listB;
    List intersection;
  };

  std::vector<TestCase> test_cases{
      {
          .listA{4, 1},
          .listB{5, 6, 1},
          .intersection{8, 4, 5},
      },
      {
          .listA{1, 9, 1},
          .listB{3},
          .intersection{2, 4},
      },
      {
          .listA{1, 2, 3},
          .listB{},
          .intersection{4, 5, 6},
      },
      {
          .listA{2, 6, 4},
          .listB{1, 5},
          .intersection{},
      },
  };

  for (const auto &[listA, listB, intersection] : test_cases) {
    auto head_a = Link(listA, intersection);
    auto head_b = Link(listB, intersection);

    const auto actual = Solution::getIntersectionNode(head_a, head_b);
    REQUIRE(intersection == List(Copy(actual)));

    Unlink(head_a, intersection);
    Unlink(head_b, intersection);
  }
}
