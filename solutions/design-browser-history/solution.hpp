#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  1472. Design Browser History
  https://leetcode.com/problems/design-browser-history/
  Difficulty: Medium
  Tags: Array, Linked List, Stack, Design, Doubly-Linked List, Data Stream
  Time:
  Space:
*/

class BrowserHistory {
public:
  BrowserHistory(std::string homepage) { history_.emplace_back(homepage); }

  void visit(std::string url) {
    history_.erase(history_.begin() + position_ + 1, history_.end());
    history_.emplace_back(url);
    position_ = history_.size() - 1;
  }

  std::string back(int steps) { return forward(-steps); }

  std::string forward(int steps) {
    int n = history_.size();
    position_ = std::min(std::max(position_ + steps, 0), n - 1);
    return history_[position_];
  }

private:
  std::vector<std::string> history_;
  int position_ = 0;
};
