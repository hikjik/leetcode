#pragma once

#include <random>

// Time: O(1) at average
// Space: O(1)

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
int rand7() {
  static std::random_device rd;
  static std::mt19937 generator(rd());
  static std::uniform_int_distribution<int> distr(1, 7);
  return distr(generator);
}

class Solution {
public:
  static int rand10() {
    int val = 0;
    do {
      val = (rand7() - 1) * 7 + rand7() - 1;
    } while (val >= 40);
    return val % 10 + 1;
  }
};
