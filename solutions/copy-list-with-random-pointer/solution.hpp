#pragma once

#include <unordered_map>

#include <list_node_with_random.h>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static Node *copyRandomList(Node *head) {
    std::unordered_map<Node *, Node *> map;
    for (auto *node = head; node; node = node->next) {
      map[node] = new Node(node->val);
    }

    for (auto *node = head; node; node = node->next) {
      map[node]->random = map[node->random];
      map[node]->next = map[node->next];
    }

    return map[head];
  }
};
