#pragma once

#include <string>
#include <unordered_set>
#include <vector>

/*
  804. Unique Morse Code Words
  https://leetcode.com/problems/unique-morse-code-words/
  Difficulty: Easy
  Tags: Array, Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static int uniqueMorseRepresentations(const std::vector<std::string> &words) {
    std::unordered_set<std::string> representations;
    for (const auto &word : words) {
      representations.insert(encodeMorse(word));
    }
    return representations.size();
  }

private:
  static std::string encodeMorse(const std::string &s) {
    static const std::vector<std::string> morse_code{
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

    std::string representation;
    for (auto c : s) {
      representation += morse_code[c - 'a'];
    }
    return representation;
  }
};
