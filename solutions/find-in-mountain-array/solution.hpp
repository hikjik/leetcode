#pragma once

#include <functional>
#include <vector>

// Time:
// Space:

class MountainArray {
public:
  MountainArray(std::vector<int> arr) : arr_(arr), cnt_(0) {}

  int get(int index) {
    ++cnt_;
    return arr_[index];
  }

  int length() const { return arr_.size(); }

  int count() const { return cnt_; }

private:
  std::vector<int> arr_;
  int cnt_;
};

class Solution {
public:
  static int findInMountainArray(int target, MountainArray &arr) {
    const auto peak = peakIndexInMountainArray(arr);

    const auto left = binarySearch(0, peak, target, std::less<int>(), arr);
    if (arr.get(left) == target) {
      return left;
    }

    const auto right = binarySearch(peak + 1, arr.length() - 1, target,
                                    std::greater<int>(), arr);
    if (arr.get(right) == target) {
      return right;
    }

    return -1;
  }

private:
  template <typename Comparator>
  static int binarySearch(int left, int right, int target, Comparator comp,
                          MountainArray &arr) {
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      comp(arr.get(middle), target) ? left = middle + 1 : right = middle;
    }
    return left;
  }

  static int peakIndexInMountainArray(MountainArray &arr) {
    auto left = 0, right = arr.length() - 1;
    while (left < right) {
      const auto middle = left + (right - left) / 2;
      arr.get(middle) < arr.get(middle + 1) ? left = middle + 1
                                            : right = middle;
    }
    return left;
  }
};
