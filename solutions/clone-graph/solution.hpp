#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

// Time: O(V+E)
// Space: O(V)

class Node {
public:
  int val;
  std::vector<Node *> neighbors;

  Node() : val(0) {}

  Node(int _val) : val(_val) {}

  Node(int _val, std::vector<Node *> _neighbors)
      : val(_val), neighbors(_neighbors) {}
};

namespace bfs {

// Time: O(V+E)
// Space: (V)
class Solution {
public:
  static Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }

    std::unordered_map<Node *, Node *> map{{node, new Node(node->val)}};
    std::queue<Node *> queue{{node}};
    while (!queue.empty()) {
      auto *node = queue.front();
      queue.pop();

      for (auto *neighbor : node->neighbors) {
        if (!map.contains(neighbor)) {
          map[neighbor] = new Node(neighbor->val);
          queue.push(neighbor);
        }
        map[node]->neighbors.push_back(map[neighbor]);
      }
    }
    return map[node];
  }
};

} // namespace bfs

namespace dfs {

// Time: O(V+E)
// Space: (V+E)
class Solution {
public:
  static Node *cloneGraph(Node *node) {
    std::unordered_map<Node *, Node *> map;
    return cloneGraph(node, &map);
  }

private:
  static Node *cloneGraph(Node *node, std::unordered_map<Node *, Node *> *map) {
    if (!node) {
      return nullptr;
    }
    if (map->contains(node)) {
      return map->at(node);
    }

    auto *clone = new Node(node->val);
    map->insert({node, clone});
    for (auto *neighbor : node->neighbors) {
      clone->neighbors.push_back(cloneGraph(neighbor, map));
    }
    return clone;
  }
};

} // namespace dfs
