#pragma once

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  static std::vector<int> majorityElement(std::vector<int> &nums) {
    int num1 = INT_MAX, num2 = INT_MAX;
    int cnt1 = 0, cnt2 = 0;
    for (auto num : nums) {
      if (num == num1) {
        ++cnt1;
      } else if (num == num2) {
        ++cnt2;
      } else if (!cnt1) {
        num1 = num;
        ++cnt1;
      } else if (!cnt2) {
        num2 = num;
        ++cnt2;
      } else {
        --cnt1, --cnt2;
      }
    }

    std::vector<int> ans;
    for (auto num : {num1, num2}) {
      const size_t cnt = std::count(nums.begin(), nums.end(), num);
      if (cnt > nums.size() / 3) {
        ans.push_back(num);
      }
    }
    return ans;
  }
};
