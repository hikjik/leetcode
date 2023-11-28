#pragma once

#include <ranges>
#include <set>
#include <unordered_map>
#include <vector>

// Time: O(NlogK), where K = indexDiff
// Space: O(K)

namespace set {

// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
  static bool containsNearbyAlmostDuplicate(const std::vector<int> &nums,
                                            int indexDiff, int valueDiff) {
    std::set<int> set;
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (auto it = set.lower_bound(nums[i] - valueDiff);
          it != set.end() && *it <= nums[i] + valueDiff) {
        return true;
      }
      set.insert(nums[i]);
      if (i >= indexDiff) {
        set.erase(nums[i - indexDiff]);
      }
    }
    return false;
  }
};

} // namespace set

namespace bucket {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static bool containsNearbyAlmostDuplicate(const std::vector<int> &nums,
                                            int indexDiff, int valueDiff) {
    const auto min = std::ranges::min(nums);
    std::unordered_map<int, int> buckets;
    for (int i = 0; i < std::ssize(nums); ++i) {
      const auto key = (nums[i] - min) / (valueDiff + 1);
      if (buckets.contains(key)) {
        return true;
      }
      if (buckets.contains(key - 1) &&
          nums[i] - buckets[key - 1] <= valueDiff) {
        return true;
      }
      if (buckets.contains(key + 1) &&
          buckets[key + 1] - nums[i] <= valueDiff) {
        return true;
      }
      buckets[key] = nums[i];
      if (i >= indexDiff) {
        buckets.erase((nums[i - indexDiff] - min) / (valueDiff + 1));
      }
    }
    return false;
  }
};

} // namespace bucket
