#include <catch.hpp>
#include <list_node.h>

#include <solution.hpp>

#include <vector>

ListNode *Advance(ListNode *head, int n) {
  auto node = head;
  for (int i = 0; i < n; ++i) {
    node = node->next;
  }
  return node;
}

void CheckSolution(const std::vector<int> &values, int pos, bool expected) {
  auto head = VectorToList(values);

  ListNode *tail = nullptr;
  if (pos != -1) {
    auto cycle_start = Advance(head, pos);
    tail = Advance(head, values.size() - 1);
    tail->next = cycle_start;
  }

  auto is_cycle = Solution::hasCycle(head);

  if (pos != -1) {
    tail->next = nullptr;
  }
  REQUIRE(expected == is_cycle);

  FreeList(head);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{3, 2, 0, -4};
    CheckSolution(values, 1, true);
  }
  {
    std::vector<int> values{1, 2};
    CheckSolution(values, 0, true);
  }
  {
    std::vector<int> values{1};
    CheckSolution(values, -1, false);
  }
  {
    std::vector<int> values;
    CheckSolution(values, -1, false);
  }
}
