#include <catch.hpp>

#include <list_node.hpp>
#include <solution.hpp>

#include <vector>

ListNode *VectorToList(std::vector<int> values) {
  ListNode *head = nullptr;
  for (auto it = values.rbegin(); it != values.rend(); ++it) {
    head = new ListNode(*it, head);
  }
  return head;
}

std::vector<int> ListToVector(ListNode *head) {
  std::vector<int> array;
  while (head) {
    array.push_back(head->val);
    head = head->next;
  }
  return array;
}

void FreeList(ListNode *node) {
  while (node) {
    auto next = node->next;
    delete node;
    node = next;
  }
}

void CheckSolution(std::vector<int> values, std::vector<int> expected) {
  auto head = VectorToList(values);
  auto reversed_list_head = Solution::reverseList(head);

  REQUIRE(expected == ListToVector(reversed_list_head));

  FreeList(reversed_list_head);
}

TEST_CASE("Simple") {
  {
    CheckSolution({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
    CheckSolution({1, 2}, {2, 1});
    CheckSolution({}, {});
  }
}
