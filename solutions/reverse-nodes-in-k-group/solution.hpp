#pragma once

#include <list_node.h>

// Time: O(N)
// Space: O(1)

namespace recursive {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static ListNode *reverseKGroup(ListNode *head, int k) {
    auto *tail = head;
    for (int i = 0; i < k; ++i) {
      if (!tail) {
        return head;
      }
      tail = tail->next;
    }

    auto *new_head = reverse(head, tail);
    head->next = reverseKGroup(tail, k);
    return new_head;
  }

private:
  static ListNode *reverse(ListNode *head, ListNode *tail) {
    ListNode *prev = nullptr;
    for (auto *curr = head; curr != tail;) {
      auto *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

} // namespace recursive

namespace iterative {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode dummy(0, head);
    auto *prev = &dummy;
    for (int i = length(head) / k; i > 0; --i) {
      auto *curr = prev->next;
      for (int j = 0; j < k - 1; ++j) {
        auto *next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
      }
      prev = curr;
    }
    return dummy.next;
  }

private:
  static int length(ListNode *head) {
    int length = 0;
    for (auto *node = head; node; node = node->next) {
      ++length;
    }
    return length;
  }
};

} // namespace iterative
