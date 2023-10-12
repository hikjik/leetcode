#pragma once

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<std::string>>
  findLadders(std::string begin_word, std::string end_word,
              const std::vector<std::string> &word_list) {
    std::unordered_set<std::string> words{word_list.begin(), word_list.end()};
    if (!words.count(end_word)) {
      return {};
    }

    std::vector<std::vector<std::string>> levels{{begin_word}};
    words.erase(begin_word);

    while (words.count(end_word)) {
      levels.push_back(getNextLevel(levels.back(), &words));
      if (levels.back().empty()) {
        return {};
      }
    }

    std::vector<std::vector<std::string>> paths;
    std::vector<std::string> path{end_word};
    dfs(levels.size() - 2, levels, &path, &paths);
    return paths;
  }

private:
  static void dfs(int i, const std::vector<std::vector<std::string>> &levels,
                  std::vector<std::string> *path,
                  std::vector<std::vector<std::string>> *paths) {
    if (i < 0) {
      paths->emplace_back(path->rbegin(), path->rend());
      return;
    }

    const auto s = path->back();
    for (const auto &p : levels[i]) {
      if (isAdjacent(s, p)) {
        path->push_back(p);
        dfs(i - 1, levels, path, paths);
        path->pop_back();
      }
    }
  }

  static std::vector<std::string>
  getNextLevel(const std::vector<std::string> &prev_level,
               std::unordered_set<std::string> *words) {
    std::vector<std::string> level;
    for (const auto &s : prev_level) {
      for (auto it = words->begin(); it != words->end();) {
        if (isAdjacent(s, *it)) {
          level.push_back(*it);
          it = words->erase(it);
        } else {
          ++it;
        }
      }
    }
    return level;
  }

  static bool isAdjacent(const std::string &s, const std::string &p) {
    int cnt = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      cnt += s[i] != p[i];
    }
    return cnt == 1;
  }
};
