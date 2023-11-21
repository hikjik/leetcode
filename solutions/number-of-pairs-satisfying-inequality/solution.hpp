#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;

// Time: O(NlogN)
// Space: O(N)
// Notes: [FenwickTree](https://w.wiki/8Cy3), [SegmentTree](https://w.wiki/8Cy4)

namespace ordered_set {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static long long numberOfPairs(const std::vector<int> &nums1,
                                 const std::vector<int> &nums2, int diff) {
    ordered_multiset<int> set;
    long long ans = 0;
    for (int i = 0; i < std::ssize(nums1); ++i) {
      ans += set.order_of_key(nums1[i] - nums2[i] + diff + 1);
      set.insert(nums1[i] - nums2[i]);
    }
    return ans;
  }
};

} // namespace ordered_set

namespace merge_sort {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static long long numberOfPairs(const std::vector<int> &nums1,
                                 const std::vector<int> &nums2, int diff) {
    std::vector<int> nums(nums1.size());
    std::transform(nums1.begin(), nums1.end(), nums2.begin(), nums.begin(),
                   std::minus{});

    long long ans = 0;
    mergeSort(nums.begin(), nums.end(), diff, &ans);
    return ans;
  }

private:
  using Iterator = std::vector<int>::iterator;

  static void mergeSort(Iterator first, Iterator last, int diff,
                        long long *ans) {
    if (first == last || std::next(first) == last) {
      return;
    }
    auto middle = first + (last - first) / 2;
    mergeSort(first, middle, diff, ans);
    mergeSort(middle, last, diff, ans);
    inplace_merge(first, middle, last, diff, ans);
  }

  static void inplace_merge(Iterator first, Iterator middle, Iterator last,
                            int diff, long long *ans) {
    for (auto left = first, right = middle; left != middle; ++left) {
      while (right != last && *left > *right + diff) {
        ++right;
      }
      *ans += last - right;
    }
    std::inplace_merge(first, middle, last);
  }
};

} // namespace merge_sort

namespace fenwick_tree {

// Time: O(NlogN)
// Space: O(M)
template <typename T = int> class BinaryIndexedTree {
public:
  explicit BinaryIndexedTree(size_t size) : tree(size + 1) {}

  template <typename U>
  explicit BinaryIndexedTree(const std::vector<U> &nums)
      : BinaryIndexedTree(nums.size()) {
    for (size_t i = 1; i < tree.size(); ++i) {
      tree[i] += nums[i - 1];
      const auto p = i + RSB(i);
      if (p < tree.size()) {
        tree[p] += tree[i];
      }
    }
  }

  void Set(size_t i, T value) {
    const auto delta = value - GetRangeSum(i, i);
    Add(i, delta);
  }

  T GetRangeSum(size_t left, size_t right) const {
    return GetPrefixSum(right) - GetPrefixSum(left - 1);
  }

  void Add(size_t i, T delta) {
    for (++i; i < tree.size(); i += RSB(i)) {
      tree[i] += delta;
    }
  }

  T GetPrefixSum(size_t i) const {
    T sum = 0;
    for (++i; i; i -= RSB(i)) {
      sum += tree[i];
    }
    return sum;
  }

  size_t UpperBound(T value) const {
    size_t i = 0;
    for (size_t j = std::bit_floor(tree.size() - 1); j; j >>= 1) {
      if (i + j < tree.size() && tree[i + j] <= value) {
        value -= tree[i + j];
        i += j;
      }
    }
    return i;
  }

private:
  size_t RSB(size_t i) const { return -i & i; }

  std::vector<T> tree;
};

class Solution {
public:
  static constexpr int kOffset = 3e4;

  static long long numberOfPairs(const std::vector<int> &nums1,
                                 const std::vector<int> &nums2, int diff) {
    BinaryIndexedTree bit(2 * kOffset);
    long long ans = 0;
    for (int i = 0; i < std::ssize(nums1); ++i) {
      ans += bit.GetPrefixSum(nums1[i] - nums2[i] + diff + kOffset - 1);
      bit.Add(nums1[i] - nums2[i] + kOffset - 1, 1);
    }
    return ans;
  }
};

} // namespace fenwick_tree

namespace segment_tree {

// Time: O(NlogN)
// Space: O(M)
template <typename ValueType, typename BinaryOp> class SegmentTree {
public:
  SegmentTree(size_t size, BinaryOp op = {}, ValueType init = {})
      : size_(size), data_(2 * size_), op_(op), init_(init) {}

  template <typename Iterator>
  SegmentTree(Iterator first, Iterator last, BinaryOp op = {},
              ValueType init = {})
      : SegmentTree(std::distance(first, last), op, init) {
    std::copy(first, last, data_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) {
      data_[i] = op_(data_[i << 1], data_[i << 1 | 1]);
    }
  }

  size_t Size() const { return size_; }

  void Set(size_t idx, ValueType value) {
    data_[idx += size_] = value;
    Update(idx);
  }

  void Add(size_t idx, ValueType delta) {
    data_[idx += size_] += delta;
    Update(idx);
  }

  // process a range query on interval [left, right]
  ValueType RangeQuery(size_t left, size_t right) const {
    auto res = init_;
    for (left += size_, right += size_ + 1; left < right;
         left >>= 1, right >>= 1) {
      if (left & 1) {
        res = op_(res, data_[left++]);
      }
      if (right & 1) {
        res = op_(res, data_[--right]);
      }
    }
    return res;
  }

private:
  void Update(size_t idx) {
    for (int i = idx; i > 1; i >>= 1) {
      data_[i >> 1] = op_(data_[i], data_[i ^ 1]);
    }
  }

  size_t size_;
  std::vector<ValueType> data_;
  BinaryOp op_;
  ValueType init_;
};

class Solution {
public:
  static constexpr int kOffset = 3e4;

  static long long numberOfPairs(const std::vector<int> &nums1,
                                 const std::vector<int> &nums2, int diff) {
    SegmentTree<int, std::plus<int>> tree(2 * kOffset);
    long long ans = 0;
    for (int i = 0; i < std::ssize(nums1); ++i) {
      ans += tree.RangeQuery(0, nums1[i] - nums2[i] + diff + kOffset - 1);
      tree.Add(nums1[i] - nums2[i] + kOffset - 1, 1);
    }
    return ans;
  }
};

} // namespace segment_tree
