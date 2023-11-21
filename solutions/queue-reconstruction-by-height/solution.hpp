#pragma once

#include <bit>
#include <ranges>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

// Time: O(NlogN)
// Space: O(N)

namespace naive {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>>
  reconstructQueue(std::vector<std::vector<int>> people) {
    std::ranges::sort(people, [&](const auto &lhs, const auto &rhs) {
      return std::tie(lhs[0], rhs[1]) > std::tie(rhs[0], lhs[1]);
    });

    std::vector<std::vector<int>> ans;
    for (auto &&p : people) {
      ans.insert(ans.begin() + p[1], std::move(p));
    }
    return ans;
  }
};

} // namespace naive

namespace oset {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>>
  reconstructQueue(const std::vector<std::vector<int>> &people) {
    std::vector<int> indexes(people.size());
    std::iota(indexes.begin(), indexes.end(), 0);

    ordered_set<int> set(indexes.begin(), indexes.end());

    std::ranges::sort(indexes, [&](const auto &i, const auto &j) {
      return std::tie(people[i][0], people[j][1]) <
             std::tie(people[j][0], people[i][1]);
    });

    std::vector<std::vector<int>> ans(people.size());
    for (auto i : indexes) {
      auto it = set.find_by_order(people[i][1]);
      ans[*it] = people[i];
      set.erase(it);
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

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static std::vector<std::vector<int>>
  reconstructQueue(std::vector<std::vector<int>> people) {
    std::ranges::sort(people, [&](const auto &lhs, const auto &rhs) {
      return std::tie(lhs[0], rhs[1]) < std::tie(rhs[0], lhs[1]);
    });

    BinaryIndexedTree bit(std::vector<int>(people.size(), 1));
    std::vector<std::vector<int>> ans(people.size());
    for (auto &&p : people) {
      const auto i = bit.UpperBound(p[1]);
      bit.Add(i, -1);
      ans[i] = std::move(p);
    }
    return ans;
  }
};

} // namespace bit
