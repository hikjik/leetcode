#pragma once

#include <list_node.h>

#include <vector>

/*
  725. Split Linked List in Parts
  https://leetcode.com/problems/split-linked-list-in-parts/
  Difficulty: Medium
  Tags: Linked List
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<ListNode *> splitListToParts(ListNode *head, int k) {
    const auto length = getLength(head);
    const auto q = length / k, r = length % k;

    std::vector<ListNode *> parts(k, nullptr);
    auto node = head;
    for (int i = 0; i < k; ++i) {
      parts[i] = node;
      for (int j = 0; j < q + (i < r) - 1; ++j) {
        node = node->next;
      }

      if (node) {
        auto next = node->next;
        node->next = nullptr;
        node = next;
      }
    }
    return parts;
  }

private:
  static int getLength(ListNode *head) {
    int length = 0;
    for (auto node = head; node; node = node->next) {
      ++length;
    }
    return length;
  }
};
