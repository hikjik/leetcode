#pragma once

#include <unordered_map>
#include <vector>

// Time:
// Space:

class FreqStack {
public:
  FreqStack() {}

  void push(int val) {
    const size_t frequency = ++frequencies[val];
    if (frequency > stacks.size()) {
      stacks.emplace_back();
    }
    stacks[frequency - 1].push_back(val);
  }

  int pop() {
    const auto top = stacks.back().back();
    stacks.back().pop_back();
    if (stacks.back().empty()) {
      stacks.pop_back();
    }
    --frequencies[top];
    return top;
  }

private:
  std::unordered_map<int, int> frequencies;
  std::vector<std::vector<int>> stacks;
};
