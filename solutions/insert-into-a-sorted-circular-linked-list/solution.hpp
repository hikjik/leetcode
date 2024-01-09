#pragma once

// Time:
// Space:

#include <list_node.h>

using Node = ListNode;

class Solution {
public:
  static Node *insert(Node *head, int insertVal) {
    if (!head) {
      auto newNode = new Node(insertVal);
      newNode->next = newNode;
      return newNode;
    }

    auto *node = head;
    do {
      if (node->val <= insertVal && insertVal <= node->next->val) {
        node->next = new Node(insertVal, node->next);
        return head;
      }
      if (node->val > node->next->val &&
          (node->val <= insertVal || insertVal <= node->next->val)) {
        node->next = new Node(insertVal, node->next);
        return head;
      }
      node = node->next;
    } while (node != head);

    head->next = new Node(insertVal, head->next);
    return head;
  }
};
