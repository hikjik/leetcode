#pragma once

#include <vector>

// Time: O(N+QlogN)
// Space: O(N)
// Notes: [FenwickTree](https://w.wiki/8Cy3), [SegmentTree](https://w.wiki/8Cy4)

namespace fenwick_tree {

// Space: O(N)
class BinaryIndexedTree {
public:
  // O(N)
  explicit BinaryIndexedTree(const std::vector<int> &nums)
      : tree(nums.size() + 1) {
    for (size_t idx = 1; idx < tree.size(); ++idx) {
      tree[idx] += nums[idx - 1];
      const auto p = idx + RSB(idx);
      if (p < tree.size()) {
        tree[p] += tree[idx];
      }
    }
  }

  // O(logN)
  void Set(size_t idx, int value) {
    const auto delta = value - GetRangeSum(idx, idx);
    Add(idx, delta);
  }

  // O(logN)
  long long GetRangeSum(size_t left, size_t right) const {
    return GetPrefixSum(right) - GetPrefixSum(left - 1);
  }

  // O(logN)
  void Add(size_t idx, int delta) {
    while (idx < tree.size()) {
      tree[idx] += delta;
      idx += RSB(idx);
    }
  }

  // O(logN)
  long long GetPrefixSum(size_t idx) const {
    long long sum = 0;
    while (idx > 0) {
      sum += tree[idx];
      idx -= RSB(idx);
    }
    return sum;
  }

private:
  size_t RSB(size_t idx) const { return -idx & idx; }

  std::vector<long long> tree;
};

class NumArray {
public:
  NumArray(const std::vector<int> &nums) : tree(nums) {}

  void update(int index, int val) { tree.Set(index + 1, val); }

  int sumRange(int left, int right) const {
    return tree.GetRangeSum(left + 1, right + 1);
  }

private:
  BinaryIndexedTree tree;
};

} // namespace fenwick_tree

namespace segment_tree {

// Space O(N)
template <typename ValueType, typename BinaryOp> class SegmentTree {
public:
  // O(N)
  SegmentTree(size_t size, BinaryOp op, ValueType init)
      : size_(size), data_(2 * size_), op_(op), init_(init) {}

  // O(N)
  template <typename Iterator>
  SegmentTree(Iterator first, Iterator last, BinaryOp op, ValueType init)
      : SegmentTree(std::distance(first, last), op, init) {
    std::copy(first, last, data_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) {
      data_[i] = op_(data_[i << 1], data_[i << 1 | 1]);
    }
  }

  size_t Size() const { return size_; }

  // O(logN)
  void Set(size_t idx, ValueType value) {
    data_[idx += size_] = value;
    Update(idx);
  }

  // O(logN)
  void Add(size_t idx, ValueType delta) {
    data_[idx += size_] += delta;
    Update(idx);
  }

  // process a range query on interval [left, right]
  // O(logN)
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

class NumArray {
public:
  NumArray(const std::vector<int> &nums)
      : tree(nums.begin(), nums.end(), {}, 0) {}

  void update(int index, int val) { tree.Set(index, val); }

  int sumRange(int left, int right) const {
    return tree.RangeQuery(left, right);
  }

private:
  SegmentTree<int, std::plus<int>> tree;
};

} // namespace segment_tree
