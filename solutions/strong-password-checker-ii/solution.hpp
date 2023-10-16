#pragma once

#include <algorithm>
#include <functional>
#include <string>

class Solution {
public:
  static bool strongPasswordCheckerII(std::string password) {
    if (password.size() < 8) {
      return false;
    }

    std::vector<std::function<bool(char)>> predicates = {
        [](char c) { return std::isdigit(c); },
        [](char c) { return std::isupper(c); },
        [](char c) { return std::islower(c); },
        [](char c) {
          static const std::string special = "!@#$%^&*()-+";
          return special.find(c) != std::string::npos;
        },
    };

    for (auto p : predicates) {
      if (!std::any_of(password.begin(), password.end(), p)) {
        return false;
      }
    }

    for (size_t i = 1; i < password.size(); ++i) {
      if (password[i] == password[i - 1]) {
        return false;
      }
    }
    return true;
  }
};
