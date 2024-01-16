#pragma once

#include <unordered_map>
#include <vector>

// Time: O(Q)
// Space: O(Q)

class RandomizedSet {
public:
  // O(1)
  bool insert(int val) {
    if (map.contains(val)) {
      return false;
    }

    map[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  // O(1)
  bool remove(int val) {
    if (auto it = map.find(val); it != map.end()) {
      map[vals.back()] = it->second;
      vals[it->second] = vals.back();
      vals.pop_back();
      map.erase(val);
      return true;
    }
    return false;
  }

  // O(1)
  int getRandom() const { return vals[rand() % vals.size()]; }

private:
  std::vector<int> vals;
  std::unordered_map<int, int> map;
};
