#pragma once

#include <queue>
#include <set>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;

// Time: O(NlogK)
// Space: O(K)

namespace oset {

// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
  static std::vector<double> medianSlidingWindow(const std::vector<int> &nums,
                                                 int k) {
    std::vector<double> ans;
    ordered_multiset<int> set;
    for (int i = 0; i < std::ssize(nums); ++i) {
      set.insert(nums[i]);
      if (i >= k) {
        set.erase(set.upper_bound(nums[i - k]));
      }
      if (i >= k - 1) {
        const auto it = set.find_by_order((k - 1) / 2);
        const auto median = k & 1 ? *it : (*it * 1.0 + *std::next(it)) / 2;
        ans.push_back(median);
      }
    }
    return ans;
  }
};

} // namespace oset

namespace multiset {

// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
  static std::vector<double> medianSlidingWindow(const std::vector<int> &nums,
                                                 int k) {
    std::vector<double> ans;
    std::multiset<int> set;
    std::multiset<int>::iterator it;
    for (int i = 0; i < std::ssize(nums); ++i) {
      set.insert(nums[i]);
      if (i == k - 1) {
        it = std::next(set.begin(), (k - 1) / 2);
      }
      if (i >= k) {
        if (nums[i] < *it) {
          --it;
        }
        if (nums[i - k] <= *it) {
          ++it;
        }
        set.erase(set.lower_bound(nums[i - k]));
      }
      if (i >= k - 1) {
        const auto median = k & 1 ? *it : (*it * 1.0 + *std::next(it)) / 2;
        ans.push_back(median);
      }
    }
    return ans;
  }
};

} // namespace multiset
