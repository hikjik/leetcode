#pragma once

#include <string>
#include <vector>

/*
  299. Bulls and Cows
  https://leetcode.com/problems/bulls-and-cows/
  Difficulty: Medium
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static std::string getHint(std::string secret, std::string guess) {
    std::vector<int> secret_count(128, 0);
    std::vector<int> guess_count(128, 0);
    int bulls = 0;
    for (size_t i = 0; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) {
        bulls++;
      } else {
        ++secret_count[secret[i]];
        ++guess_count[guess[i]];
      }
    }

    int cows = 0;
    for (size_t i = 0; i < secret_count.size(); ++i) {
      cows += std::min(secret_count[i], guess_count[i]);
    }
    return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
  }
};
