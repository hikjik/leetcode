#pragma once

#include <string>
#include <vector>

/*
  68. Text Justification
  https://leetcode.com/problems/text-justification/
  Difficulty: Hard
  Tags: Array, String, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::string>
  fullJustify(const std::vector<std::string> &words, size_t max_width) {
    std::vector<std::string> ans;

    std::vector<std::string> row;
    size_t letters_cnt = 0;
    for (const auto &word : words) {
      if (row.size() + letters_cnt + word.size() > max_width) {
        const auto spaces = max_width - letters_cnt;
        if (row.size() == 1) {
          ans.push_back(pad_right(row[0], spaces));
        } else {
          for (size_t i = 0; i < spaces; ++i) {
            row[i % (row.size() - 1)] += " ";
          }
          ans.push_back(join(row, ""));
        }

        row.clear();
        letters_cnt = 0;
      }
      row.push_back(word);
      letters_cnt += word.size();
    }
    const auto spaces = max_width - letters_cnt - row.size() + 1;
    ans.push_back(pad_right(join(row, " "), spaces));

    return ans;
  }

private:
  static std::string join(const std::vector<std::string> &words,
                          const std::string &delimeter) {
    std::string res;
    for (size_t i = 0; i < words.size(); ++i) {
      res += words[i];
      if (i + 1 != words.size()) {
        res += delimeter;
      }
    }
    return res;
  }

  static std::string pad_right(const std::string &s, size_t count) {
    return s + std::string(count, ' ');
  }
};
