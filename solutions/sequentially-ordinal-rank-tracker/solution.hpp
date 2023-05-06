#pragma once

#include <queue>
#include <string>

class SORTracker {
private:
  struct Location {
    Location(std::string name, int score) : name(name), score(score) {}

    std::string name;
    int score;
  };

  struct LocationLess {
    bool operator()(const Location &lhs, const Location &rhs) {
      return lhs.score == rhs.score ? lhs.name > rhs.name
                                    : lhs.score < rhs.score;
    }
  };

  struct LocationGreater {
    bool operator()(const Location &lhs, const Location &rhs) {
      return lhs.score == rhs.score ? lhs.name < rhs.name
                                    : lhs.score > rhs.score;
    }
  };

  std::priority_queue<Location, std::vector<Location>, LocationLess> max_heap;
  std::priority_queue<Location, std::vector<Location>, LocationGreater>
      min_heap;
  size_t k = 0;

public:
  void add(std::string name, int score) {
    min_heap.emplace(name, score);
    if (min_heap.size() > k + 1) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  std::string get() {
    const auto name = min_heap.top().name;
    ++k;

    if (!max_heap.empty()) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }

    return name;
  }
};
