#pragma once

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int ladderLength(std::string begin_word, std::string end_word,
                          const std::vector<std::string> &word_list) {
    std::unordered_set<std::string> words{word_list.begin(), word_list.end()};

    std::queue<std::pair<std::string, int>> queue;
    queue.emplace(begin_word, 0);
    words.erase(begin_word);
    while (!queue.empty()) {
      auto [word, distance] = queue.front();
      queue.pop();

      if (word == end_word) {
        return distance + 1;
      }

      for (size_t i = 0; i < word.size(); ++i) {
        char symbol = word[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          word[i] = c;
          if (words.count(word)) {
            queue.emplace(word, distance + 1);
            words.erase(word);
          }
        }
        word[i] = symbol;
      }
    }
    return 0;
  }
};
