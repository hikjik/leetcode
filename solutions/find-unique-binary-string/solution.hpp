#pragma once

#include <bitset>
#include <string>
#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(N)
// Notes: [Cantor's diagonal argument](https://w.wiki/FMY)

namespace hash_table {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static std::string
  findDifferentBinaryString(const std::vector<std::string> &nums) {
    std::unordered_set<int> seen;
    for (const auto &num : nums) {
      seen.insert(std::stoi(num, nullptr, 2));
    }

    for (int num = 0; num <= std::ssize(nums); ++num) {
      if (!seen.contains(num)) {
        return std::bitset<16>(num).to_string().substr(16 - nums.size());
      }
    }
    throw;
  }
};

} // namespace hash_table

namespace cantor {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::string
  findDifferentBinaryString(const std::vector<std::string> &nums) {
    std::string ans;
    for (int i = 0; i < std::ssize(nums); ++i) {
      ans += nums[i][i] == '0' ? '1' : '0';
    }
    return ans;
  }
};

} // namespace cantor
