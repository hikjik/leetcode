#pragma once

#include <list>
#include <unordered_map>
#include <vector>

// Time: O(1) for get and put
// Space: O(C), where C is the cache capacity

class LRUCache {
public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (auto it = map.find(key); it == map.end()) {
      return -1;
    } else {
      nodes.splice(nodes.end(), nodes, it->second);
      return it->second->value;
    }
  }

  void put(int key, int value) {
    if (auto it = map.find(key); it == map.end()) {
      map[key] = nodes.insert(nodes.end(), {key, value});
    } else {
      it->second->value = value;
      nodes.splice(nodes.end(), nodes, it->second);
    }

    if (capacity < nodes.size()) {
      map.erase(nodes.begin()->key);
      nodes.pop_front();
    }
  }

private:
  struct Node {
    int key;
    int value;
  };

  std::list<Node> nodes;
  std::unordered_map<int, std::list<Node>::iterator> map;
  size_t capacity;
};
