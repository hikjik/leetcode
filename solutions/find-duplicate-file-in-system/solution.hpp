#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// Time: O(NK)
// Space: O(NK)

class Solution {
public:
  static std::vector<std::vector<std::string>>
  findDuplicate(const std::vector<std::string> &paths) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const auto &path : paths) {
      std::stringstream sstream(path);

      std::string directory;
      sstream >> directory;

      for (std::string file; sstream >> file;) {
        const auto start = file.find_first_of('(');
        const auto end = file.find_first_of(')', start + 1);
        const auto filename = file.substr(0, start);
        const auto content = file.substr(start + 1, end - start - 1);
        groups[content].push_back(directory + "/" + filename);
      }
    }

    std::vector<std::vector<std::string>> ans;
    for (auto &[_, group] : groups) {
      if (group.size() > 1) {
        ans.push_back(std::move(group));
      }
    }
    return ans;
  }
};
