#pragma once

#include <ranges>
#include <string>
#include <unordered_map>

// N is the length of the key
// M is the length of the message
// A is the size of the alphabet
// Time: O(N+M)
// Space: O(A+N)

class Solution {
public:
  static std::string decodeMessage(std::string key, std::string message) {
    std::unordered_map<char, char> table{{' ', ' '}};
    for (auto s = 'a'; auto c : key) {
      if (!table.contains(c)) {
        table[c] = s++;
      }
    }

    std::ranges::transform(message, message.begin(),
                           [&](auto c) { return table[c]; });
    return message;
  }
};
