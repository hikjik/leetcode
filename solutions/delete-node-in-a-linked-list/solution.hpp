#pragma once

#include <list_node.h>

/*
  237. Delete Node in a Linked List
  https://leetcode.com/problems/delete-node-in-a-linked-list/
  Difficulty: Medium
  Tags: Linked List
  Time:
  Space:
*/

class Solution {
public:
  static void deleteNode(ListNode *node) {
    auto to_delete = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete to_delete;
  }
};
