#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string capitalizeTitle(std::string title) {
    for (size_t i = 0; i < title.size(); ++i) {
      if ((!i || title[i - 1] == ' ') && i + 2 < title.size() &&
          title.substr(i + 1, 2).find(' ') == std::string::npos) {
        title[i] = std::toupper(title[i]);
      } else {
        title[i] = std::tolower(title[i]);
      }
    }
    return title;
  }
};
