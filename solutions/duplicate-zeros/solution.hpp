#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static void duplicateZeros(std::vector<int> &arr) {
    const auto zeros = std::count(arr.begin(), arr.end(), 0);
    for (int i = arr.size() - 1, j = i + zeros; i >= 0; --i, --j) {
      if (j < std::ssize(arr)) {
        arr[j] = arr[i];
      }
      if (arr[i] == 0 && --j < std::ssize(arr)) {
        arr[j] = arr[i];
      }
    }
  }
};
