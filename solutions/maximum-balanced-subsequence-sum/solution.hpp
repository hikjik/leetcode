#pragma once

#include <climits>
#include <ranges>
#include <vector>

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

template <typename ValueType> struct Max {
  ValueType operator()(ValueType lhs, ValueType rhs) const {
    return std::max(lhs, rhs);
  }
};

class Solution {
public:
  static long long maxBalancedSubsequenceSum(const std::vector<int> &nums) {
    std::vector<std::pair<int, int>> pairs(nums.size());
    for (int i = 0; i < std::ssize(nums); ++i) {
      pairs[i] = {nums[i] - i, i};
    }
    std::ranges::sort(pairs);

    SegmentTree<long long, Max<long long>> tree(nums.size() + 1);

    auto ans = LLONG_MIN;
    for (const auto &[_, i] : pairs) {
      const auto sum = tree.RangeQuery(0, i);
      ans = std::max(ans, sum + nums[i]);
      tree.Set(i + 1, sum + nums[i]);
    }
    return ans;
  }
};
