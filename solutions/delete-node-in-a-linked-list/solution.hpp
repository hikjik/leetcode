#pragma once

#include <list_node.h>

class Solution {
public:
  static void deleteNode(ListNode *node) {
    auto to_delete = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete to_delete;
  }
};
