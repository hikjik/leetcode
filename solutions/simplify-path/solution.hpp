#pragma once

#include <sstream>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::string simplifyPath(std::string path) {
    std::stringstream sstream(path);
    std::vector<std::string> dirs;
    for (std::string dir; std::getline(sstream, dir, '/');) {
      if (dir.empty() || dir == ".") {
        continue;
      }
      if (dir == "..") {
        if (!dirs.empty()) {
          dirs.pop_back();
        }
      } else {
        dirs.push_back(dir);
      }
    }

    if (dirs.empty()) {
      return "/";
    }

    std::string canonical;
    for (const auto &dir : dirs) {
      canonical += "/" + dir;
    }
    return canonical;
  }
};
