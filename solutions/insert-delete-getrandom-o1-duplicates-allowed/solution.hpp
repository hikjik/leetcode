#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(Q)
// Space: O(Q)

class RandomizedCollection {
public:
  // O(1)
  bool insert(int val) {
    const auto ret = !map.contains(val);
    map[val].insert(vals.size());
    vals.push_back(val);
    return ret;
  }

  // O(1)
  bool remove(int val) {
    if (map.contains(val)) {
      const auto top = vals.back();
      const auto pos = *map[val].begin();

      map[top].erase(vals.size() - 1);
      std::swap(vals[pos], vals.back());
      vals.pop_back();

      if (top != val) {
        map[val].erase(pos);
        map[top].insert(pos);
      }

      if (map[val].empty()) {
        map.erase(val);
      }
      return true;
    }
    return false;
  }

  // O(1)
  int getRandom() const { return vals[rand() % vals.size()]; }

private:
  std::vector<int> vals;
  std::unordered_map<int, std::unordered_set<int>> map;
};
