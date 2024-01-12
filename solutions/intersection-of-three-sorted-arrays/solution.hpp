#pragma once

#include <vector>

// Time: O(N+M+K)
// Space: O(1)

namespace three_pointers {

// Time: O(N+M+K)
// Space: O(1)
class Solution {
public:
  static std::vector<int> arraysIntersection(const std::vector<int> &arr1,
                                             const std::vector<int> &arr2,
                                             const std::vector<int> &arr3) {
    std::vector<int> ans;
    for (size_t i = 0, j = 0, k = 0;
         i < arr1.size() && j < arr2.size() && k < arr3.size();) {
      if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
        ans.push_back(arr1[i]);
        ++i, ++j, ++k;
      } else {
        arr1[i] < arr2[j] ? ++i : arr2[j] < arr3[k] ? ++j : ++k;
      }
    }
    return ans;
  }
};

} // namespace three_pointers

namespace stl {

// Time: O(N+M+K)
// Space: O(1)
class Solution {
public:
  static std::vector<int> arraysIntersection(const std::vector<int> &arr1,
                                             const std::vector<int> &arr2,
                                             const std::vector<int> &arr3) {
    std::vector<int> a12, a123;
    std::ranges::set_intersection(arr1, arr2, std::back_inserter(a12));
    std::ranges::set_intersection(a12, arr3, std::back_inserter(a123));
    return a123;
  }
};

} // namespace stl
