#pragma once

#include <algorithm>
#include <array>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

// Time: O(NM), where N is the number of strs and M is the max length of the str
// Space: O(NM)

namespace naive {

// Time: O(N^2M)
// Space: O(A), where is the size of the alphabet
class Solution {
public:
  static constexpr size_t kSize = 26;

  static std::vector<std::vector<std::string>>
  groupAnagrams(const std::vector<std::string> &strs) {
    std::vector<std::vector<std::string>> groups;
    for (const auto &str : strs) {
      auto it = std::ranges::find_if(
          groups, [&](const auto &group) { return isAnagram(group[0], str); });
      if (it != groups.end()) {
        it->push_back(str);
      } else {
        groups.push_back({str});
      }
    }
    return groups;
  }

  static bool isAnagram(const std::string &str1, const std::string &str2) {
    if (str1.size() != str2.size()) {
      return false;
    }
    std::array<int, kSize> counter{};
    for (size_t i = 0; i < str1.size(); ++i) {
      ++counter[str1[i] - 'a'];
      --counter[str2[i] - 'a'];
    }
    return std::ranges::all_of(counter, [](int a) { return a == 0; });
  }
};

} // namespace naive

namespace sorting {

// Time: O(NMlogM)
// Space: O(NM)
class Solution {
public:
  static std::vector<std::vector<std::string>>
  groupAnagrams(const std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (const auto &str : strs) {
      auto key = str;
      std::sort(key.begin(), key.end());
      map[key].push_back(str);
    }

    std::vector<std::vector<std::string>> groups;
    for (const auto &[key, anagrams] : map) {
      groups.push_back(anagrams);
    }
    return groups;
  }
};

} // namespace sorting

namespace counting {

// Time: O(NM)
// Space: O(NM)
template <typename ValueType, size_t Size> struct ArrayHasher {
  size_t operator()(const std::array<ValueType, Size> &arr) const {
    std::hash<ValueType> hasher;
    size_t result = 17;
    for (auto a : arr) {
      result = result * 31 + hasher(a);
    }
    return result;
  }
};

class Solution {
public:
  static constexpr size_t kSize = 26;

  static std::vector<std::vector<std::string>>
  groupAnagrams(const std::vector<std::string> &strs) {
    std::unordered_map<std::array<int, kSize>, std::vector<std::string>,
                       ArrayHasher<int, kSize>>
        map;
    for (const auto &str : strs) {
      std::array<int, kSize> arr{};
      for (auto c : str) {
        ++arr[c - 'a'];
      }
      map[arr].push_back(str);
    }

    std::vector<std::vector<std::string>> groups;
    for (const auto &[_, anagrams] : map) {
      groups.push_back(anagrams);
    }
    return groups;
  }
};

} // namespace counting
