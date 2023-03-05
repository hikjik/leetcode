#pragma once

#include <list_node.h>

class Solution {
public:
  static bool isPalindrome(ListNode *head) {
    if (!head || !head->next) {
      return true;
    }

    auto node = advance(head, listLength(head) / 2 - 1);
    auto reversed = reverseList(node->next);
    const auto is_palindrome = isPrefix(reversed, head);
    node->next = reverseList(reversed);
    return is_palindrome;
  }

private:
  static int listLength(ListNode *node) {
    int length = 0;
    while (node) {
      length++;
      node = node->next;
    }
    return length;
  }

  static ListNode *advance(ListNode *node, int n) {
    while (n-- && node) {
      node = node->next;
    }
    return node;
  }

  static ListNode *reverseList(ListNode *head) {
    ListNode *reversed = nullptr;
    auto node = head;
    while (node) {
      auto next = node->next;
      node->next = reversed;
      reversed = node;
      node = next;
    }
    return reversed;
  }

  static bool isPrefix(ListNode *prefix_head, ListNode *head) {
    while (prefix_head) {
      if (prefix_head->val != head->val) {
        return false;
      }
      prefix_head = prefix_head->next;
      head = head->next;
    }
    return true;
  }
};
