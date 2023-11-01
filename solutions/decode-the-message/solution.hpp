#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

/*
  2325. Decode the Message
  https://leetcode.com/problems/decode-the-message/
  Difficulty: Easy
  Tags: Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static std::string decodeMessage(std::string key, std::string message) {
    std::unordered_map<char, char> table{{' ', ' '}};
    for (auto c : key) {
      if (!table.contains(c)) {
        table[c] = 'a' + table.size() - 1;
      }
    }

    std::transform(message.begin(), message.end(), message.begin(),
                   [&table](char c) { return table[c]; });
    return message;
  }
};
