#pragma once

#include <list_node.h>

#include <random>

class Solution {
public:
  Solution(ListNode *head) : head(head) {}

  int getRandom() {
    int value = -1;
    int scope = 1;
    for (auto node = head; node; node = node->next, ++scope) {
      if (rand() % scope == 0) {
        value = node->val;
      }
    }
    return value;
  }

private:
  ListNode *head;
};
