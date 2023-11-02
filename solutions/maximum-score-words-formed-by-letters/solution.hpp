#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxScoreWords(const std::vector<std::string> &words,
                           const std::vector<char> &letters,
                           const std::vector<int> &scores) {
    std::unordered_map<char, int> frequencies;
    for (auto c : letters) {
      frequencies[c]++;
    }
    return dfs(0, 0, words, scores, &frequencies);
  }

private:
  static int dfs(size_t i, int score, const std::vector<std::string> &words,
                 const std::vector<int> &scores,
                 std::unordered_map<char, int> *frequencies) {
    if (i == words.size()) {
      return score;
    }
    int max_score = dfs(i + 1, score, words, scores, frequencies);

    bool acceptable = true;
    for (auto c : words[i]) {
      if (--(*frequencies)[c] < 0) {
        acceptable = false;
      }
      score += scores[c - 'a'];
    }
    if (acceptable) {
      max_score =
          std::max(max_score, dfs(i + 1, score, words, scores, frequencies));
    }
    for (auto c : words[i]) {
      (*frequencies)[c]++;
    }
    return max_score;
  }
};
