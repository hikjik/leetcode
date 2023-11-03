#pragma once

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

// Time: O(NM^N), where M = 3, i.e. max number length, N = 4, i.e. IP4 length
// Space: O(N)

namespace brute_force {

// Time: O(NM^N)
// Space: O(N)
class Solution {
public:
  static std::vector<std::string> restoreIpAddresses(std::string s) {
    const int n = s.size();
    std::vector<std::string> addresses;
    for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 3; ++j) {
        for (int k = 1; k <= 3; ++k) {
          if (i + j + k < n - 3 || i + j + k > n - 1) {
            continue;
          }
          if (isValid(s.substr(0, i)) && isValid(s.substr(i, j)) &&
              isValid(s.substr(i + j, k)) && isValid(s.substr(i + j + k))) {
            addresses.push_back(s.substr(0, i) + "." + s.substr(i, j) + "." +
                                s.substr(i + j, k) + "." + s.substr(i + j + k));
          }
        }
      }
    }
    return addresses;
  }

private:
  static bool isValid(std::string_view s) {
    if (s.size() > 1 && s.starts_with('0')) {
      return false;
    }
    return s.size() != 3 || s <= "255";
  }
};

} // namespace brute_force

namespace backtracking {

// Time: O(NM^N)
// Space: O(N)
class Solution {
public:
  static std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string_view> nums;
    std::vector<std::string> addresses;
    restoreIpAddresses(std::string_view(s), &nums, &addresses);
    return addresses;
  }

private:
  static void restoreIpAddresses(std::string_view s,
                                 std::vector<std::string_view> *nums,
                                 std::vector<std::string> *addresses) {
    if (s.empty() && nums->size() == 4) {
      addresses->push_back(buildIpAddress(*nums));
      return;
    }
    if (s.empty() || nums->size() == 4) {
      return;
    }

    for (int i = 1; i <= 3 && i <= std::ssize(s); ++i) {
      if (isValid(s.substr(0, i))) {
        nums->push_back(s.substr(0, i));
        restoreIpAddresses(s.substr(i), nums, addresses);
        nums->pop_back();
      }
    }
  }

  static bool isValid(std::string_view s) {
    if (s.size() > 1 && s.starts_with('0')) {
      return false;
    }
    return s.size() != 3 || s <= "255";
  }

  static std::string buildIpAddress(const std::vector<std::string_view> &nums) {
    std::ostringstream ostream;
    std::copy(nums.begin(), std::prev(nums.end()),
              std::ostream_iterator<std::string_view>(ostream, "."));
    return ostream.str() + std::string(nums.back());
  }
};

} // namespace backtracking
