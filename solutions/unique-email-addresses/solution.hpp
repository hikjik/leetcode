#pragma once

#include <string>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int numUniqueEmails(const std::vector<std::string> &emails) {
    std::unordered_set<std::string> set;
    for (const auto &email : emails) {
      set.insert(normalize(email));
    }
    return set.size();
  }

  static std::string normalize(const std::string &email) {
    std::string local_name;
    for (auto c : email) {
      if (c == '.') {
        continue;
      }
      if (c == '+' || c == '@') {
        break;
      }
      local_name.push_back(c);
    }
    return local_name + email.substr(email.find('@'));
  }
};
