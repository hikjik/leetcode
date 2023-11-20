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
  static int reversePairs(const std::vector<int> &nums) {
    ordered_multiset<long long> set;
    int ans = 0;
    for (auto a : nums) {
      ans += set.size() - set.order_of_key(a * 2LL + 1);
      set.insert(a);
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
  static int reversePairs(std::vector<int> nums) {
    int ans = 0;
    mergeSort(nums.begin(), nums.end(), &ans);
    return ans;
  }

private:
  using Iterator = std::vector<int>::iterator;

  static void mergeSort(Iterator first, Iterator last, int *ans) {
    if (first == last || std::next(first) == last) {
      return;
    }
    auto middle = first + (last - first) / 2;
    mergeSort(first, middle, ans);
    mergeSort(middle, last, ans);
    inplace_merge(first, middle, last, ans);
  }

  static void inplace_merge(Iterator first, Iterator middle, Iterator last,
                            int *ans) {
    for (auto left = first, right = middle; left != middle; ++left) {
      while (right != last && *left <= *right * 2LL) {
        ++right;
      }
      *ans += last - right;
    }
    std::inplace_merge(first, middle, last, std::greater{});
  }
};

} // namespace merge_sort

namespace fenwick_tree {

// Time: O(NlogN)
// Space: O(N)
class BinaryIndexedTree {
public:
  explicit BinaryIndexedTree(int size) : tree(size + 1) {}

  explicit BinaryIndexedTree(const std::vector<int> &nums)
      : BinaryIndexedTree(nums.size()) {
    for (size_t idx = 1; idx < tree.size(); ++idx) {
      tree[idx] += nums[idx - 1];
      const auto p = idx + RSB(idx);
      if (p < tree.size()) {
        tree[p] += tree[idx];
      }
    }
  }

  void Set(size_t idx, int value) {
    const auto delta = value - GetRangeSum(idx, idx);
    Add(idx, delta);
  }

  int GetRangeSum(size_t left, size_t right) const {
    return GetPrefixSum(right) - GetPrefixSum(left - 1);
  }

  void Add(size_t idx, int delta) {
    while (idx < tree.size()) {
      tree[idx] += delta;
      idx += RSB(idx);
    }
  }

  int GetPrefixSum(size_t idx) const {
    int sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= RSB(idx);
    }
    return sum;
  }

private:
  size_t RSB(size_t idx) const { return -idx & idx; }

  std::vector<int> tree;
};

class Solution {
public:
  static int reversePairs(const std::vector<int> &nums) {
    std::vector<int> copy(nums);
    std::ranges::sort(copy);

    BinaryIndexedTree bit(nums.size() + 1);

    int ans = 0;
    for (auto a : nums) {
      ans += bit.GetPrefixSum(1 + rank(copy, 2LL * a + 1));
      bit.Add(1 + rank(copy, a), 1);
    }
    return ans;
  }

private:
  static int rank(const std::vector<int> &nums, long long num) {
    return std::distance(std::ranges::lower_bound(nums, num), nums.end());
  }
};

} // namespace fenwick_tree

namespace segment_tree {

// Time: O(NlogN)
// Space: O(N)
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
  static int reversePairs(const std::vector<int> &nums) {
    std::vector<int> copy(nums);
    std::ranges::sort(copy);

    SegmentTree<int, std::plus<int>> tree(nums.size() + 1);

    int ans = 0;
    for (auto a : nums) {
      ans += tree.RangeQuery(0, rank(copy, 2LL * a + 1));
      tree.Add(rank(copy, a), 1);
    }
    return ans;
  }

private:
  static int rank(const std::vector<int> &nums, long long num) {
    return std::distance(std::ranges::lower_bound(nums, num), nums.end());
  }
};

} // namespace segment_tree
