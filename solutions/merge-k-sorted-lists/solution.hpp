#pragma once

#include <list_node.h>

#include <queue>
#include <vector>

class Solution {
private:
  using Element = std::tuple<int, size_t, size_t>;

public:
  static ListNode *mergeKLists(std::vector<ListNode *> lists) {
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>>
        queue;
    for (size_t i = 0; i < lists.size(); ++i) {
      if (lists[i]) {
        queue.emplace(lists[i]->val, i, 0);
        lists[i] = lists[i]->next;
      }
    }

    auto dummy_node = ListNode();
    auto dummy = &dummy_node;

    auto node = dummy;
    while (!queue.empty()) {
      const auto [value, index, position] = queue.top();
      queue.pop();

      node->next = new ListNode(value);
      node = node->next;

      if (lists[index]) {
        queue.emplace(lists[index]->val, index, position + 1);
        lists[index] = lists[index]->next;
      }
    }

    return dummy->next;
  }
};
