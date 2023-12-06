#pragma once

#include <list>
#include <numeric>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

// Time: O(QlogM)
// Space: O(M)

namespace naive {

// Time: O(QM)
// Space: O(M)
class Solution {
public:
  static std::vector<int> processQueries(const std::vector<int> &queries,
                                         int m) {
    std::vector<int> nums(m);
    std::iota(nums.begin(), nums.end(), 1);

    std::vector<int> ans;
    for (auto q : queries) {
      auto it = std::find(nums.begin(), nums.end(), q);
      ans.push_back(it - nums.begin());
      nums.erase(it);
      nums.insert(nums.begin(), q);
    }
    return ans;
  }
};

} // namespace naive

namespace list {

// Time: O(QM)
// Space: O(M)
class Solution {
public:
  using Iterator = std::list<int>::iterator;

  static std::vector<int> processQueries(const std::vector<int> &queries,
                                         int m) {
    std::list<int> list;
    std::vector<Iterator> positions(m + 1, list.begin());
    for (int i = 1; i <= m; ++i) {
      positions[i] = list.insert(list.end(), i);
    }

    std::vector<int> ans;
    for (auto q : queries) {
      ans.push_back(std::distance(list.begin(), positions[q]));
      list.splice(list.begin(), list, positions[q]);
      positions[q] = list.begin();
    }
    return ans;
  }
};

} // namespace list

namespace oset {

// Time: O(QlogM)
// Space: O(M)
class Solution {
public:
  static std::vector<int> processQueries(const std::vector<int> &queries,
                                         int m) {
    ordered_set<int> set;
    std::vector<int> indexes(m + 1);
    for (int i = 1; i <= m; ++i) {
      set.insert(i);
      indexes[i] = i;
    }

    std::vector<int> ans;
    for (int i = 0; i < std::ssize(queries); ++i) {
      const auto index = indexes[queries[i]];
      ans.push_back(set.order_of_key(index));
      set.insert(-i);
      set.erase(index);
      indexes[queries[i]] = -i;
    }
    return ans;
  }
};

} // namespace oset

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

// Time: O(QlogM)
// Space: O(M)
class Solution {
public:
  static std::vector<int> processQueries(const std::vector<int> &queries,
                                         int m) {
    const int n = queries.size();

    BinaryIndexedTree tree(m + n);
    std::vector<int> indexes(m + 1);
    for (int i = 1; i <= m; ++i) {
      tree.Add(i + n - 1, 1);
      indexes[i] = i + n - 1;
    }

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      const auto index = indexes[queries[i]];
      ans.push_back(tree.GetPrefixSum(index - 1));
      tree.Add(index, -1);
      tree.Add(n - 1 - i, 1);
      indexes[queries[i]] = n - 1 - i;
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

// Time: O(QlogM)
// Space: O(M)
class Solution {
public:
  static std::vector<int> processQueries(const std::vector<int> &queries,
                                         int m) {
    const int n = queries.size();

    SegmentTree<int, std::plus<int>> tree(m + n);
    std::vector<int> indexes(m + 1);
    for (int i = 1; i <= m; ++i) {
      tree.Add(i + n - 1, 1);
      indexes[i] = i + n - 1;
    }

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      const auto index = indexes[queries[i]];
      ans.push_back(tree.RangeQuery(0, index - 1));
      tree.Add(index, -1);
      tree.Add(n - 1 - i, 1);
      indexes[queries[i]] = n - 1 - i;
    }
    return ans;
  }
};

} // namespace segment_tree
