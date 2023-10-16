#pragma once

#include <deque>
#include <string>

class Solution {
public:
  static std::string finalString(std::string s) {
    std::deque<char> deque;

    bool inv = false;
    for (auto c : s) {
      if (c == 'i') {
        inv = !inv;
      } else {
        inv ? deque.push_front(c) : deque.push_back(c);
      }
    }

    if (inv) {
      return {deque.rbegin(), deque.rend()};
    }
    return {deque.begin(), deque.end()};
  }
};