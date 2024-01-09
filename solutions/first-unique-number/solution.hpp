#pragma once

#include <list>
#include <unordered_map>
#include <vector>

// Time: O(N+Q)
// Space: O(N+Q)

class FirstUnique {
public:
  // O(N)
  explicit FirstUnique(const std::vector<int> &nums) {
    for (auto num : nums) {
      add(num);
    }
  }

  // O(1)
  int showFirstUnique() const { return list.empty() ? -1 : list.front(); }

  // O(1)
  void add(int value) {
    if (auto it = map.find(value); it != map.end()) {
      if (it->second != list.end()) {
        list.erase(it->second);
        it->second = list.end();
      }
    } else {
      map[value] = list.insert(list.end(), value);
    }
  }

private:
  std::list<int> list;
  std::unordered_map<int, std::list<int>::iterator> map;
};
