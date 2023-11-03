#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// Time: O(NK), where N is the length of s, K is the length of word
// Space: O(M), where M is the number of words

class Solution {
public:
  static std::vector<int> findSubstring(const std::string &s,
                                        const std::vector<std::string> &words) {
    const int word_size = words[0].size();
    const int concat_size = word_size * words.size();
    const std::string_view view(s);

    std::unordered_map<std::string_view, int> counter;
    for (const auto &word : words) {
      ++counter[word];
    }

    std::vector<int> ans;
    for (int i = 0; i < word_size; ++i) {
      auto left = i, right = i;
      while (right + word_size <= std::ssize(view)) {
        const auto word = view.substr(right, word_size);
        right += word_size;
        if (counter.contains(word)) {
          if (--counter[word] >= 0 && right - left == concat_size) {
            ans.push_back(left);
          }
          while (counter[word] < 0 || right - left == concat_size) {
            ++counter[view.substr(left, word_size)];
            left += word_size;
          }
        } else {
          while (left < right - word_size) {
            ++counter[view.substr(left, word_size)];
            left += word_size;
          }
          left = right;
        }
      }
      while (left < right) {
        ++counter[view.substr(left, word_size)];
        left += word_size;
      }
    }
    return ans;
  }
};
