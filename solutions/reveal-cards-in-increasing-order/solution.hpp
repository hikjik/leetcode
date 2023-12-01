#pragma once

#include <deque>
#include <queue>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace queue {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> deckRevealedIncreasing(std::vector<int> deck) {
    std::ranges::sort(deck);

    std::queue<int> queue;
    for (int i = 0; i < std::ssize(deck); ++i) {
      queue.push(i);
    }

    std::vector<int> ans(deck.size());
    for (auto card : deck) {
      ans[queue.front()] = card;
      queue.pop();
      queue.push(queue.front());
      queue.pop();
    }
    return ans;
  }
};

} // namespace queue

namespace deque {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::vector<int> deckRevealedIncreasing(std::vector<int> deck) {
    std::ranges::sort(deck, std::greater{});

    std::deque<int> deque;
    for (auto card : deck) {
      if (!deque.empty()) {
        deque.push_front(deque.back());
        deque.pop_back();
      }
      deque.push_front(card);
    }
    return {deque.begin(), deque.end()};
  }
};

} // namespace deque
