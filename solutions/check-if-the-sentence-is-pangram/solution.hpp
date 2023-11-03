#pragma once

#include <string>
#include <unordered_set>

// Time:
// Space:

class Solution {
public:
  static bool checkIfPangram(std::string sentence) {
    return std::unordered_set(sentence.begin(), sentence.end()).size() == 26;
  }
};
