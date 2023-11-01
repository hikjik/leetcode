#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

/*
  133. Clone Graph
  https://leetcode.com/problems/clone-graph/
  Difficulty: Medium
  Tags: Hash Table, Depth-First Search, Breadth-First Search, Graph
  Time:
  Space:
*/

class Node {
public:
  int val;
  std::vector<Node *> neighbors;

  Node() : val(0) {}

  Node(int _val) : val(_val) {}

  Node(int _val, std::vector<Node *> _neighbors)
      : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
  static Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }

    std::unordered_map<Node *, Node *> nodes{
        {node, new Node(node->val)},
    };
    std::queue<Node *> queue{{node}};

    while (!queue.empty()) {
      auto node = queue.front();
      queue.pop();

      for (auto neighbor : node->neighbors) {
        if (!nodes.count(neighbor)) {
          nodes[neighbor] = new Node(neighbor->val);
          queue.push(neighbor);
        }
        nodes[node]->neighbors.push_back(nodes[neighbor]);
      }
    }

    return nodes[node];
  }
};
