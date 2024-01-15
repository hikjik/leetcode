#pragma once

#include <list>
#include <map>
#include <stack>

// Time: O(QlogQ)
// Space: O(Q)

class MaxStack {
public:
  // O(logN)
  void push(int x) { map[x].push(list.insert(list.end(), x)); }

  // O(logN)
  int pop() {
    const auto res = top();
    map[res].pop();
    if (map[res].empty()) {
      map.erase(res);
    }
    list.pop_back();
    return res;
  }

  // O(1)
  int top() const { return list.back(); }

  // O(1)
  int peekMax() const { return map.rbegin()->first; }

  // O(logN)
  int popMax() {
    const auto max = peekMax();
    list.erase(map.rbegin()->second.top());
    map.rbegin()->second.pop();
    if (map.rbegin()->second.empty()) {
      map.erase(max);
    }
    return max;
  }

private:
  using Iterator = std::list<int>::const_iterator;

  std::list<int> list;
  std::map<int, std::stack<Iterator>> map;
};
