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

void CheckSolution(const std::vector<int> &values, int pos,
                   const std::vector<int> &expected) {
  auto head = VectorToList(values);

  ListNode *tail = nullptr;
  if (pos != -1) {
    auto cycle_start = Advance(head, pos);
    tail = Advance(head, values.size() - 1);
    tail->next = cycle_start;
  }

  auto cycle_detected = Solution::detectCycle(head);

  if (pos != -1) {
    tail->next = nullptr;
  }
  REQUIRE(expected == ListToVector(cycle_detected));

  FreeList(head);
}

TEST_CASE("Simple") {
  {
    std::vector<int> values{3, 2, 0, -4};
    int pos = 1;
    std::vector<int> expected{2, 0, -4};
    CheckSolution(values, pos, expected);
  }
  {
    std::vector<int> values{1, 2};
    int pos = 0;
    std::vector<int> expected{1, 2};
    CheckSolution(values, pos, expected);
  }
  {
    std::vector<int> values{1};
    int pos = -1;
    std::vector<int> expected;
    CheckSolution(values, pos, expected);
  }
  {
    std::vector<int> values;
    int pos = -1;
    std::vector<int> expected;
    CheckSolution(values, pos, expected);
  }
}
