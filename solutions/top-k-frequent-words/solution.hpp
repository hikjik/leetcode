#pragma once

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string>
  topKFrequent(const std::vector<std::string> &words, int k) {
    std::unordered_map<std::string, int> umap;
    for (const auto &word : words) {
      umap[word]++;
    }

    std::priority_queue<std::pair<int, std::string>,
                        std::vector<std::pair<int, std::string>>,
                        std::greater<>>
        queue;
    for (const auto &[word, frequency] : umap) {
      queue.emplace(-frequency, word);
    }

    std::vector<std::string> top;
    while (k--) {
      top.push_back(queue.top().second);
      queue.pop();
    }
    return top;
  }
};
