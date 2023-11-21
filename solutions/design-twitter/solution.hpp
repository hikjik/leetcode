#pragma once

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Time: O(Q(N+KlogN))
// Space: O(N)

struct Tweet {
  int id;
  int ts;
};

// TODO replace with std::ranges::subrange
template <typename Iterator> class IteratorRange {
public:
  IteratorRange(Iterator begin, Iterator end) : begin_(begin), end_(end) {}

  bool empty() const { return begin_ == end_; }

  IteratorRange next() const { return {std::next(begin_), end_}; }

  auto front() { return *begin_; }

private:
  Iterator begin_;
  Iterator end_;
};

using TweetReverseIterator = std::vector<Tweet>::const_reverse_iterator;
using TweetReversedRange = IteratorRange<TweetReverseIterator>;

bool operator<(TweetReversedRange lhs, TweetReversedRange rhs) {
  return lhs.front().ts < rhs.front().ts;
}

struct User {
  void follow(int followeeId) { followees.insert(followeeId); }

  void unfollow(int followeeId) { followees.erase(followeeId); }

  void postTweet(Tweet tweet) { tweets.push_back(tweet); }

  std::unordered_set<int> followees;
  std::vector<Tweet> tweets;
};

class Twitter {
  static constexpr size_t kTop = 10;

public:
  // O(1)
  void postTweet(int userId, int tweetId) {
    users[userId].postTweet({tweetId, clock++});
  }

  // Time: O(N+KlogN), K tweets from N followees users
  // Space: O(N)
  std::vector<int> getNewsFeed(int userId) {
    follow(userId, userId);

    std::priority_queue<TweetReversedRange> maxHeap;
    for (auto followeeId : users[userId].followees) {
      if (const auto &tweets = users[followeeId].tweets; !tweets.empty()) {
        maxHeap.push({tweets.crbegin(), tweets.crend()});
      }
    }

    std::vector<int> tweetsIds;
    while (!maxHeap.empty() && tweetsIds.size() < kTop) {
      auto range = maxHeap.top();
      maxHeap.pop();

      tweetsIds.push_back(range.front().id);
      range = range.next();
      if (!range.empty()) {
        maxHeap.push(range);
      }
    }
    return tweetsIds;
  }

  // O(1)
  void follow(int followerId, int followeeId) {
    users[followerId].follow(followeeId);
  }

  // O(1)
  void unfollow(int followerId, int followeeId) {
    users[followerId].unfollow(followeeId);
  }

private:
  std::unordered_map<int, User> users;
  int clock = 0;
};
