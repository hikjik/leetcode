#pragma once

/*
  1823. Find the Winner of the Circular Game
  https://leetcode.com/problems/find-the-winner-of-the-circular-game/
  Difficulty: Medium
  Tags: Array, Math, Recursion, Queue, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int findTheWinner(int n, int k) { return f(n, k) + 1; }

private:
  // f(n, k) - index of winner
  // f(n, k) = (f(n - 1, k) + k) % n
  // f(1, k) = 0
  static int f(int n, int k) {
    int winner_index = 0;
    for (int i = 2; i <= n; ++i) {
      winner_index = (winner_index + k) % i;
    }
    return winner_index;
  }
};
