#pragma once

#include <list_node.h>

#include <stack>

/*
  445. Add Two Numbers II
  https://leetcode.com/problems/add-two-numbers-ii/
  Difficulty: Medium
  Tags: Linked List, Math, Stack
  Time:
  Space:
*/

class Solution {
public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto stack1 = stackList(l1), stack2 = stackList(l2);
    int carry = 0;
    ListNode *head = nullptr;
    while (!stack1.empty() || !stack2.empty() || carry) {
      int val = carry;
      if (!stack1.empty()) {
        val += stack1.top();
        stack1.pop();
      }
      if (!stack2.empty()) {
        val += stack2.top();
        stack2.pop();
      }
      carry = val / 10;
      head = new ListNode(val % 10, head);
    }
    return head;
  }

private:
  static std::stack<int> stackList(ListNode *node) {
    std::stack<int> stack;
    while (node) {
      stack.push(node->val);
      node = node->next;
    }
    return stack;
  }
};
