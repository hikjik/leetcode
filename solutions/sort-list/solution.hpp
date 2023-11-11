#pragma once

#include <list_node.h>

// Time: O(NlogN)
// Space: O(1)

namespace recursive {

// Time: O(NlogN)
// Space: O(logN)
class Solution {
public:
  static ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    auto *slow = head;
    auto *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto *left = head;
    auto *right = slow->next;
    slow->next = nullptr;

    return mergeLists(sortList(left), sortList(right));
  }

private:
  static ListNode *mergeLists(ListNode *list1, ListNode *list2) {
    ListNode dummy;
    for (auto *node = &dummy; list1 || list2; node = node->next) {
      if (!list1 || !list2) {
        node->next = list1 ? list1 : list2;
        break;
      }
      if (list2->val < list1->val) {
        std::swap(list1, list2);
      }
      node->next = list1;
      list1 = list1->next;
    }
    return dummy.next;
  }
};

} // namespace recursive

namespace iterative {

// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
  static ListNode *sortList(ListNode *head) {
    const auto length = getLength(head);
    ListNode dummy(0, head);
    for (int gap = 1; gap < length; gap *= 2) {
      auto *prev = &dummy;
      for (auto *first = prev->next; first; first = prev->next) {
        auto *middle = advance(first, gap);
        if (!middle) {
          break;
        }
        auto *last = advance(middle, gap);
        prev = merge(prev, first, middle, last);
      }
    }
    return dummy.next;
  }

private:
  static ListNode *merge(ListNode *prev, ListNode *first, ListNode *middle,
                         ListNode *last) {
    auto *first1 = first, *last1 = middle;
    auto *first2 = middle, *last2 = last;
    while (first1 != last1 || first2 != last2) {
      if (first2 == last2 || first1 != last1 && first1->val < first2->val) {
        prev->next = first1;
        first1 = first1->next;
      } else {
        prev->next = first2;
        first2 = first2->next;
      }
      prev = prev->next;
    }
    prev->next = last;
    return prev;
  }

  static ListNode *advance(ListNode *node, int k) {
    while (k-- && node) {
      node = node->next;
    }
    return node;
  }

  static int getLength(ListNode *head) {
    int length = 0;
    for (auto *node = head; node; node = node->next) {
      ++length;
    }
    return length;
  }
};

} // namespace iterative
