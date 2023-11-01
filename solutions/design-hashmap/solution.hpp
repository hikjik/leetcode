#pragma once

#include <list>
#include <vector>

/*
  706. Design HashMap
  https://leetcode.com/problems/design-hashmap/
  Difficulty: Easy
  Tags: Array, Hash Table, Linked List, Design, Hash Function
  Time:
  Space:
*/

class MyHashMap {
private:
  using MapNode = std::pair<int, int>;

  std::vector<std::list<MapNode>> buckets_;
  size_t size_;
  float max_load_factor_ = 1.0;

  std::list<MapNode> &bucket(int key) {
    const auto index = std::hash<int>()(key) % buckets_.size();
    return buckets_[index];
  }

  void rehash() {
    std::vector<std::list<MapNode>> buckets(2 * buckets_.size());

    buckets_.swap(buckets);
    size_ = 0;
    for (const auto &list : buckets) {
      for (const auto &[key, value] : list) {
        put(key, value);
      }
    }
  }

public:
  MyHashMap() : buckets_(11) {}

  void put(int key, int value) {
    auto &list = bucket(key);
    for (auto &node : list) {
      if (node.first == key) {
        node.second = value;
        return;
      }
    }

    list.emplace_front(key, value);
    size_++;

    auto load_factor = (1.0 * size_) / buckets_.size();
    if (load_factor > max_load_factor_) {
      rehash();
    }
  }

  int get(int key) {
    auto list = bucket(key);
    for (const auto &node : list) {
      if (node.first == key) {
        return node.second;
      }
    }
    return -1;
  }

  void remove(int key) {
    auto &list = bucket(key);
    for (auto it = list.begin(); it != list.end(); ++it) {
      if (it->first == key) {
        list.erase(it);
        size_--;
        return;
      }
    }
  }
};
