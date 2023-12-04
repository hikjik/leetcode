#pragma once

#include <vector>

// Time: O(Q)
// Space: O(Q)

class CustomStack {
public:
  // O(1)
  CustomStack(int maxSize) : maxSize(maxSize) {}

  // O(1)
  void push(int x) {
    if (std::ssize(vals) < maxSize) {
      vals.push_back(x);
      incs.push_back(0);
    }
  }

  // O(1)
  int pop() {
    if (vals.empty()) {
      return -1;
    }
    const int top = vals.back() + incs.back();
    if (std::ssize(incs) > 1) {
      incs[incs.size() - 2] += incs.back();
    }
    vals.pop_back();
    incs.pop_back();
    return top;
  }

  // O(1)
  void increment(int k, int val) {
    k = std::min<int>(k, vals.size());
    if (k) {
      incs[k - 1] += val;
    }
  }

private:
  std::vector<int> vals;
  std::vector<int> incs;
  int maxSize;
};
