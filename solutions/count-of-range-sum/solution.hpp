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

namespace o_set {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int countRangeSum(const std::vector<int> &nums, int lower, int upper) {
    int ans = 0;
    ordered_multiset<long long> set;
    for (long long sum = 0; auto x : nums) {
      set.insert(sum);
      sum += x;
      ans += set.order_of_key(sum - lower + 1) - set.order_of_key(sum - upper);
    }
    return ans;
  }
};

} // namespace o_set

namespace merge_sort {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int countRangeSum(const std::vector<int> &nums, int lower, int upper) {
    std::vector<long long> partial_sum(nums.size() + 1);
    std::inclusive_scan(nums.begin(), nums.end(), partial_sum.begin() + 1,
                        std::plus{}, 0LL);

    int ans = 0;
    mergeSort(partial_sum.begin(), partial_sum.end(), lower, upper, &ans);
    return ans;
  }

private:
  using Iterator = std::vector<long long>::iterator;

  static void mergeSort(Iterator first, Iterator last, int lower, int upper,
                        int *ans) {
    if (first == last || std::next(first) == last) {
      return;
    }
    const auto middle = first + (last - first) / 2;
    mergeSort(first, middle, lower, upper, ans);
    mergeSort(middle, last, lower, upper, ans);
    inplaceMerge(first, middle, last, lower, upper, ans);
  }

  static void inplaceMerge(Iterator first, Iterator middle, Iterator last,
                           int lower, int upper, int *ans) {
    for (auto low = middle, high = middle, it = first; it != middle; ++it) {
      while (low != last && *low - *it < lower) {
        ++low;
      }
      while (high != last && *high - *it <= upper) {
        ++high;
      }
      *ans += high - low;
    }
    std::inplace_merge(first, middle, last);
  }
};

} // namespace merge_sort

namespace bit {

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

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int countRangeSum(const std::vector<int> &nums, int lower, int upper) {
    std::vector<long long> sums(nums.size() + 1);
    std::inclusive_scan(nums.begin(), nums.end(), sums.begin() + 1, std::plus{},
                        0LL);
    std::ranges::sort(sums);

    auto order = [&](long long x) {
      return std::ranges::lower_bound(sums, x) - sums.begin();
    };

    int ans = 0;
    BinaryIndexedTree tree(sums.size());
    for (long long sum = 0; auto x : nums) {
      tree.Add(order(sum), 1);
      sum += x;
      ans += tree.GetRangeSum(order(sum - upper), order(sum - lower + 1) - 1);
    }

    return ans;
  }
};

} // namespace bit

namespace segment_tree {

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

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int countRangeSum(const std::vector<int> &nums, int lower, int upper) {
    std::vector<long long> sums(nums.size() + 1);
    std::inclusive_scan(nums.begin(), nums.end(), sums.begin() + 1, std::plus{},
                        0LL);
    std::ranges::sort(sums);

    auto order = [&](long long x) {
      return std::ranges::lower_bound(sums, x) - sums.begin();
    };

    int ans = 0;
    SegmentTree<int, std::plus<>> tree(sums.size());
    for (long long sum = 0; auto x : nums) {
      tree.Add(order(sum), 1);
      sum += x;
      ans += tree.RangeQuery(order(sum - upper), order(sum - lower + 1) - 1);
    }

    return ans;
  }
};

} // namespace segment_tree
