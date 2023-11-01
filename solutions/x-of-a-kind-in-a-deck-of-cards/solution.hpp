#pragma once

#include <numeric>
#include <unordered_map>
#include <vector>

/*
  914. X of a Kind in a Deck of Cards
  https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
  Difficulty: Easy
  Tags: Array, Hash Table, Math, Counting, Number Theory
  Time:
  Space:
*/

class Solution {
public:
  static bool hasGroupsSizeX(const std::vector<int> &deck) {
    std::unordered_map<int, int> counter;
    for (auto a : deck) {
      ++counter[a];
    }

    int gcd = counter[deck[0]];
    for (const auto &[_, f] : counter) {
      gcd = std::gcd(gcd, f);
    }
    return gcd > 1;
  }
};
