#pragma once

#include <unordered_map>

// Time: O(QN)
// Space: O(QN)

class TwoSum {
public:
  // O(1)
  void add(int number) { ++counter[number]; }

  // O(N)
  bool find(int value) {
    for (const auto &[num, cnt] : counter) {
      const auto remain = static_cast<long long>(value) - num;
      if (num == remain && cnt > 1) {
        return true;
      }
      if (num != remain && counter.contains(remain)) {
        return true;
      }
    }
    return false;
  }

private:
  std::unordered_map<int, int> counter;
};
