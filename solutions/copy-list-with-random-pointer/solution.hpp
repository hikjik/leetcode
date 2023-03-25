#pragma once

#include <unordered_map>

#include <list_node_with_random.h>

class Solution {
public:
  static Node *copyRandomList(Node *head) {
    std::unordered_map<Node *, Node *> map;

    Node dummy(0);
    auto node = head, copy = &dummy;
    while (node) {
      copy->next = new Node(node->val);
      copy = copy->next;
      map[node] = copy;
      node = node->next;
    }

    node = head;
    while (node) {
      if (node->random) {
        map[node]->random = map[node->random];
      }
      node = node->next;
    }

    return dummy.next;
  }
};