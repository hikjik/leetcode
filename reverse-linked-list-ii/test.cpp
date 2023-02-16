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

void CheckSolution(std::vector<int> values, int left, int right,
                   std::vector<int> expected) {
  auto head = VectorToList(values);
  auto reversed_list_head = Solution::reverseBetween(head, left, right);

  REQUIRE(expected == ListToVector(reversed_list_head));

  FreeList(reversed_list_head);
}

TEST_CASE("Simple") {
  CheckSolution({1, 2, 3, 4, 5}, 2, 4, {1, 4, 3, 2, 5});
  CheckSolution({1, 2, 3, 4, 5}, 2, 2, {1, 2, 3, 4, 5});
  CheckSolution({1, 2, 3, 4, 5}, 1, 4, {4, 3, 2, 1, 5});
  CheckSolution({5}, 1, 1, {5});
  CheckSolution({3, 5}, 1, 1, {3, 5});
  CheckSolution({3, 5}, 1, 2, {5, 3});
}
