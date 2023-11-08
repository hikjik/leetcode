#pragma once

#include <numeric>
#include <queue>
#include <span>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

// N is the number of words in the wordList
// K is the maximum word length
// A is the size of the alphabet
// Time: O(NA^K)
// Space: O(NK)

class Solution {
public:
  static std::vector<std::vector<std::string>>
  findLadders(std::string source, std::string target,
              const std::vector<std::string> &wordList) {
    const auto layers = bfs(source, target, wordList);
    std::vector<std::vector<std::string>> ladders;
    std::vector<std::string> ladder;
    dfs(std::span{layers}, &ladder, &ladders);
    return ladders;
  }

private:
  static void dfs(std::span<const std::vector<std::string_view>> layers,
                  std::vector<std::string> *ladder,
                  std::vector<std::vector<std::string>> *ladders) {
    if (layers.empty()) {
      if (!ladder->empty()) {
        ladders->emplace_back(ladder->rbegin(), ladder->rend());
      }
      return;
    }

    for (auto p : layers.front()) {
      if (ladder->empty() || hammingDistance(ladder->back(), p) == 1) {
        ladder->emplace_back(p);
        dfs(layers.subspan(1), ladder, ladders);
        ladder->pop_back();
      }
    }
  }

  static std::vector<std::vector<std::string_view>>
  bfs(std::string_view source, std::string_view target,
      const std::vector<std::string> &wordList) {
    std::unordered_set<std::string_view> words{wordList.begin(),
                                               wordList.end()};
    if (!words.contains(target)) {
      return {};
    }
    words.erase(source);

    std::vector<std::vector<std::string_view>> layers{{source}};
    while (words.contains(target)) {
      std::vector<std::string_view> layer;
      for (auto word : layers.back()) {
        for (auto adj : adjacentWords(word, words)) {
          layer.push_back(adj);
          words.erase(adj);
        }
      }
      if (layer.empty()) {
        return {};
      }
      layers.push_back(std::move(layer));
    }
    layers.back() = {target};
    std::reverse(layers.begin(), layers.end());
    return layers;
  }

  static std::vector<std::string_view>
  adjacentWords(std::string_view s,
                const std::unordered_set<std::string_view> &words) {
    std::vector<std::string_view> adjacent;
    auto word = std::string(s);
    for (auto &c : word) {
      const auto cache = c;
      for (c = 'a'; c <= 'z'; ++c) {
        if (auto it = words.find(word); it != words.end()) {
          adjacent.push_back(*it);
        }
      }
      c = cache;
    }
    return adjacent;
  }

  static int hammingDistance(std::string_view s, std::string_view p) {
    return std::inner_product(s.cbegin(), s.cend(), p.cbegin(), 0, std::plus{},
                              std::not_equal_to{});
  }
};
