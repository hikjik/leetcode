#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<std::string>
  subdomainVisits(const std::vector<std::string> &cpdomains) {
    std::unordered_map<std::string, int> counter;
    for (const auto &cpdomain : cpdomains) {
      auto pos = cpdomain.find_first_of(' ');
      const int rep = std::stoi(cpdomain.substr(0, pos));
      while (pos != std::string::npos) {
        counter[cpdomain.substr(pos + 1)] += rep;
        pos = cpdomain.find_first_of('.', pos + 1);
      }
    }

    std::vector<std::string> ans;
    for (const auto &[domain, rep] : counter) {
      ans.push_back(std::to_string(rep) + " " + domain);
    }
    return ans;
  }
};
