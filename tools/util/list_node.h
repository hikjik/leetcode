#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
