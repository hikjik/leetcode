#pragma once

#include <immutable_list_node.h>

#include <stack>

// Time: O(N)
// Space: O(N)

namespace recursion {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static void printLinkedListInReverse(ImmutableListNode *head) {
    if (!head) {
      return;
    }
    printLinkedListInReverse(head->getNext());
    head->printValue();
  }
};

} // namespace recursion

namespace stack {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static void printLinkedListInReverse(ImmutableListNode *head) {
    std::stack<ImmutableListNode *> stack;
    for (auto *node = head; node; node = node->getNext()) {
      stack.push(node);
    }

    while (!stack.empty()) {
      stack.top()->printValue();
      stack.pop();
    }
  }
};

} // namespace stack
