#pragma once

#include <list>
#include <vector>

/*
  705. Design HashSet
  https://leetcode.com/problems/design-hashset/
  Difficulty: Easy
  Tags: Array, Hash Table, Linked List, Design, Hash Function
  Time:
  Space:
*/

class MyHashSet {
public:
  MyHashSet() : buckets_(11) {}

  void add(int key) {
    if (contains(key)) {
      return;
    }

    get_bucket(key).push_front(key);
    ++size_;

    auto load_factor = (1.0 * size_) / buckets_.size();
    if (load_factor > max_load_factor_) {
      rehash();
    }
  }

  void remove(int key) {
    auto &bucket = get_bucket(key);
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
      if (*it == key) {
        bucket.erase(it);
        --size_;
        return;
      }
    }
  }

  bool contains(int key) {
    for (auto k : get_bucket(key)) {
      if (k == key) {
        return true;
      }
    }
    return false;
  }

private:
  std::vector<std::list<int>> buckets_;
  size_t size_;
  float max_load_factor_ = 1.0;

  std::list<int> &get_bucket(int key) {
    const auto index = std::hash<int>()(key) % buckets_.size();
    return buckets_[index];
  }

  void rehash() {
    std::vector<std::list<int>> buckets(2 * buckets_.size());
    buckets_.swap(buckets);
    size_ = 0;
    for (const auto &bucket : buckets) {
      for (auto key : bucket) {
        add(key);
      }
    }
  }
};
