#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> addresses;
    std::vector<std::string> parts;
    restoreIpAddresses(0, s, &parts, &addresses);
    return addresses;
  }

private:
  static void restoreIpAddresses(size_t i, const std::string &s,
                                 std::vector<std::string> *parts,
                                 std::vector<std::string> *addresses) {
    if (i == s.size() && parts->size() == 4) {
      addresses->push_back(buildIpAddress(*parts));
      return;
    }
    if (i == s.size() || parts->size() == 4) {
      return;
    }
    for (auto n : {1, 2, 3}) {
      if (i + n > s.size()) {
        return;
      }
      if (n > 1 && s[i] == '0') {
        return;
      }
      if (255 < std::stoi(s.substr(i, n))) {
        return;
      }
      parts->push_back(s.substr(i, n));
      restoreIpAddresses(i + n, s, parts, addresses);
      parts->pop_back();
    }
  }

  static std::string buildIpAddress(const std::vector<std::string> &parts) {
    std::string address;
    for (size_t i = 0; i < 4; ++i) {
      address += parts[i];
      if (i != 3) {
        address += '.';
      }
    }
    return address;
  }
};
