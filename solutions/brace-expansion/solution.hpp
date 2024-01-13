#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <vector>

// Time: O(N3^N)
// Space: O(N3^N)

namespace iterative {

// Time: O(N3^N)
// Space: O(N3^N)
class Solution {
public:
  static std::vector<std::string> expand(std::string s) {
    std::vector<std::string> words{""};
    std::string options;
    for (int i = 0; i <= std::ssize(s); ++i) {
      if (i == std::ssize(s) || s[i] == '{') {
        if (!options.empty()) {
          for (auto &word : words) {
            word += options;
          }
          options.clear();
        }
      } else if (s[i] == '}') {
        std::ranges::sort(options);
        std::vector<std::string> tmp;
        for (const auto &word : words) {
          for (auto c : options) {
            tmp.push_back(word + c);
          }
        }
        words.swap(tmp);
        options.clear();
      } else if (std::isalpha(s[i])) {
        options += s[i];
      }
    }
    return words;
  }
};

} // namespace iterative

namespace recursive {

// Time: O(N3^N)
// Space: O(N3^N)
class Solution {
public:
  static std::vector<std::string> expand(std::string s) {
    if (s.empty()) {
      return {""};
    }
    std::vector<std::string> ans;
    if (s.starts_with('{')) {
      const int j = s.find_first_of('}');
      std::string options;
      for (int i = 1; i < j; ++i) {
        if (std::isalpha(s[i])) {
          options.push_back(s[i]);
        }
      }
      std::ranges::sort(options);
      const auto words = expand(s.substr(j + 1));
      for (auto c : options) {
        for (const auto &word : words) {
          ans.push_back(c + word);
        }
      }
    } else {
      for (const auto &word : expand(s.substr(1))) {
        ans.push_back(s[0] + word);
      }
    }
    return ans;
  }
};

} // namespace recursive

namespace backtracking {

// Time: O(N3^N)
// Space: O(N3^N)
class Solution {
public:
  static std::vector<std::string> expand(std::string s) {
    std::vector<std::string> words;
    std::string word;

    std::function<void(std::string_view)> dfs = [&](std::string_view s) {
      if (s.empty()) {
        words.push_back(word);
        return;
      }
      if (s.starts_with('{')) {
        const int j = s.find_first_of('}');
        std::string options;
        for (auto c : s.substr(1, j - 1)) {
          if (std::isalpha(c)) {
            options.push_back(c);
          }
        }
        std::ranges::sort(options);

        for (auto c : options) {
          word.push_back(c);
          dfs(s.substr(j + 1));
          word.pop_back();
        }
      } else {
        word.push_back(s.front());
        dfs(s.substr(1));
        word.pop_back();
      }
    };

    dfs(s);
    return words;
  }
};

} // namespace backtracking
