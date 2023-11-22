#pragma once

#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>

// Time: O(N), where N is the number of calls
// Space: O(N)

class AllOne {
public:
  // O(1)
  void inc(std::string key) {
    if (!map.contains(key)) {
      if (list.empty() || list.begin()->cnt != 1) {
        map[key] = list.insert(list.begin(), Node(1));
      } else {
        map[key] = list.begin();
      }
    } else {
      auto it = map[key];
      map[key] = getNext(it);
      it->erase(key);
      if (it->empty()) {
        list.erase(it);
      }
    }
    map[key]->insert(key);
  }

  // O(1)
  void dec(std::string key) {
    auto it = map[key];
    if (it->cnt > 1) {
      map[key] = getPrev(it);
      map[key]->insert(key);
    } else {
      map.erase(key);
    }
    it->erase(key);
    if (it->empty()) {
      list.erase(it);
    }
  }

  // O(1)
  std::string getMaxKey() { return list.empty() ? "" : *list.back().cbegin(); }

  // O(1)
  std::string getMinKey() { return list.empty() ? "" : *list.front().cbegin(); }

private:
  struct Node : public std::unordered_set<std::string> {
    explicit Node(int cnt) : cnt(cnt) {}

    int cnt;
  };

  using Iterator = std::list<Node>::iterator;

  Iterator getNext(Iterator it) {
    const auto next = std::next(it);
    if (next == list.end() || next->cnt != it->cnt + 1) {
      return list.insert(next, Node(it->cnt + 1));
    }
    return next;
  }

  Iterator getPrev(Iterator it) {
    const auto prev = std::prev(it);
    if (prev->cnt != it->cnt - 1) {
      return list.insert(it, Node(it->cnt - 1));
    }
    return prev;
  }

  std::list<Node> list;
  std::unordered_map<std::string, Iterator> map;
};
