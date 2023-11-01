#pragma once

#include <sstream>
#include <string>
#include <vector>

/*
  71. Simplify Path
  https://leetcode.com/problems/simplify-path/
  Difficulty: Medium
  Tags: String, Stack
  Time:
  Space:
*/

class Solution {
public:
  static std::string simplifyPath(std::string path) {
    std::stringstream sstream(path);
    std::vector<std::string> stack;
    for (std::string dir; std::getline(sstream, dir, '/');) {
      if (dir.empty() || dir == ".") {
        continue;
      }
      if (dir == "..") {
        if (!stack.empty()) {
          stack.pop_back();
        }
      } else {
        stack.push_back(dir);
      }
    }

    if (stack.empty()) {
      return "/";
    }

    std::string canonical;
    for (const auto &dir : stack) {
      canonical += "/" + dir;
    }
    return canonical;
  }
};
