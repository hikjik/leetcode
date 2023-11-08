#pragma once

#include <queue>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

// N is the number of words in the wordList
// K is the maximum word length
// A is the size of the alphabet
// Time: O(NA^K)
// Space: O(N)

class Solution {
public:
  static int ladderLength(std::string source, std::string target,
                          const std::vector<std::string> &wordList) {
    std::unordered_set<std::string_view> words{wordList.begin(),
                                               wordList.end()};
    words.erase(source);
    if (!words.contains(target)) {
      return 0;
    }

    std::queue<std::string_view> queue{{source}};
    for (int distance = 1; !queue.empty(); ++distance) {
      for (int sz = queue.size(); sz; --sz) {
        auto word = std::string(queue.front());
        queue.pop();

        for (auto &c : word) {
          const auto cache = c;
          for (c = 'a'; c <= 'z'; ++c) {
            if (auto it = words.find(word); it != words.end()) {
              if (word == target) {
                return distance + 1;
              }
              queue.push(*it);
              words.erase(it);
            }
          }
          c = cache;
        }
      }
    }
    return 0;
  }
};
