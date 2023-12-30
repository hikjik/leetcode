#pragma once

#include <climits>
#include <stack>

#include <list_node.h>

// Time: O(N)
// Space: O(N)

namespace recursion {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static ListNode *removeNodes(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    head->next = removeNodes(head->next);
    return head->next && head->val < head->next->val ? head->next : head;
  }
};

} // namespace recursion

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static ListNode *removeNodes(ListNode *head) {
    ListNode dummy(INT_MAX, head);
    std::stack<ListNode *> stack{{&dummy}};
    for (auto *node = head; node; node = node->next) {
      while (stack.top()->val < node->val) {
        stack.pop();
      }
      stack.top()->next = node;
      stack.push(node);
    }
    return dummy.next;
  }
};

} // namespace stack
