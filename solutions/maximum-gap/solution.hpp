#pragma once

#include <climits>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
private:
  struct Bucket {
    void put(int num) {
      min = std::min(min, num);
      max = std::max(max, num);
    }

    bool empty() const { return min == INT_MAX; }

    int min = INT_MAX;
    int max = INT_MIN;
  };

public:
  static int maximumGap(const std::vector<int> &nums) {
    const int n = nums.size();
    const auto [min, max] = std::ranges::minmax(nums);
    if (min == max) {
      return 0;
    }

    const auto bucket_size = (max - min + (n - 1) - 1) / (n - 1);
    std::vector<Bucket> buckets(n);
    for (auto num : nums) {
      buckets[(num - min) / bucket_size].put(num);
    }

    int ans = 0;
    for (auto prevMax = min; const auto &bucket : buckets) {
      if (bucket.empty()) {
        continue;
      }
      ans = std::max(ans, bucket.min - prevMax);
      prevMax = bucket.max;
    }
    return ans;
  }
};
