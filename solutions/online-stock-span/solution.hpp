#pragma once

#include <stack>

// Time:
// Space:

class StockSpanner {
public:
  int next(int price) {
    int cnt = 1;
    while (!stack_.empty() && stack_.top().first <= price) {
      cnt += stack_.top().second;
      stack_.pop();
    }
    stack_.emplace(price, cnt);
    return cnt;
  }

private:
  std::stack<std::pair<int, int>> stack_;
};
