#pragma once

#include <list>
#include <unordered_map>
#include <vector>

/*
  146. LRU Cache
  https://leetcode.com/problems/lru-cache/
  Difficulty: Medium
  Tags: Hash Table, Linked List, Design, Doubly-Linked List
  Time:
  Space:
*/

class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (auto it = nodes_.find(key); it == nodes_.end()) {
      return -1;
    } else {
      items_.splice(items_.end(), items_, it->second);
      return it->second->value;
    }
  }

  void put(int key, int value) {
    if (auto it = nodes_.find(key); it == nodes_.end()) {
      nodes_[key] = items_.insert(items_.end(), {key, value});
    } else {
      it->second->value = value;
      items_.splice(items_.end(), items_, it->second);
    }

    if (capacity_ < items_.size()) {
      nodes_.erase(items_.begin()->key);
      items_.pop_front();
    }
  }

private:
  struct Item {
    int key;
    int value;
  };

  std::list<Item> items_;
  std::unordered_map<int, std::list<Item>::iterator> nodes_;
  size_t capacity_;
};
