#pragma once

#include <functional>
#include <numeric>
#include <ranges>
#include <vector>

// M = max(ages)
// Time: O(NlogN+NlogM)
// Space: O(N+M)

namespace memo {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  struct Player {
    Player(int score, int age) : score(score), age(age) {}

    int score;
    int age;
  };

  static int bestTeamScore(const std::vector<int> &scores,
                           const std::vector<int> &ages) {
    const int n = ages.size();
    std::vector<Player> players;
    for (int i = 0; i < n; ++i) {
      players.push_back({scores[i], ages[i]});
    }
    std::ranges::sort(players, [&](const auto &p1, const auto &p2) {
      return std::tie(p1.age, p1.score) < std::tie(p2.age, p2.score);
    });

    std::vector memo(n, std::vector<int>(n, -1));
    std::function<int(int, int)> bestScore = [&](int i, int p) {
      if (i == n) {
        return 0;
      }
      if (memo[i][p + 1] != -1) {
        return memo[i][p + 1];
      }
      memo[i][p + 1] = bestScore(i + 1, p);
      if (p == -1 || players[i].score >= players[p].score) {
        memo[i][p + 1] =
            std::max(memo[i][p + 1], players[i].score + bestScore(i + 1, i));
      }
      return memo[i][p + 1];
    };

    return bestScore(0, -1);
  }
};

} // namespace memo

namespace dp {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  struct Player {
    Player(int score, int age) : score(score), age(age) {}

    int score;
    int age;
  };

  static int bestTeamScore(const std::vector<int> &scores,
                           const std::vector<int> &ages) {
    const int n = ages.size();
    std::vector<Player> players;
    for (int i = 0; i < n; ++i) {
      players.push_back({scores[i], ages[i]});
    }
    std::ranges::sort(players, [&](const auto &p1, const auto &p2) {
      return std::tie(p1.age, p1.score) < std::tie(p2.age, p2.score);
    });

    std::vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      dp[i] = players[i].score;
      for (int j = 0; j < i; ++j) {
        if (players[j].score <= players[i].score) {
          dp[i] = std::max(dp[i], players[i].score + dp[j]);
        }
      }
    }
    return std::ranges::max(dp);
  }
};

} // namespace dp

namespace st {

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

// Time: O(NlogN+NlogM)
// Space: O(N+M)
class Solution {
public:
  struct Player {
    Player(int score, int age) : score(score), age(age) {}

    int score;
    int age;
  };

  static int bestTeamScore(const std::vector<int> &scores,
                           const std::vector<int> &ages) {
    const int n = ages.size();
    std::vector<Player> players;
    for (int i = 0; i < n; ++i) {
      players.push_back({scores[i], ages[i]});
    }
    std::ranges::sort(players, [&](const auto &p1, const auto &p2) {
      return std::tie(p1.score, p1.age) < std::tie(p2.score, p2.age);
    });

    SegmentTree<int, Max<int>> tree(std::ranges::max(ages) + 1);

    int ans = 0;
    for (const auto &player : players) {
      const auto score = player.score + tree.RangeQuery(0, player.age);
      tree.Set(player.age, score);
      ans = std::max(ans, score);
    }
    return ans;
  }
};

} // namespace st
