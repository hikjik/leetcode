#pragma once

#include <array>
#include <string>

// Time: O(logN)
// Space: O(logN)

class Solution {
public:
  static std::string numberToWords(int num) {
    static const std::array<std::string, 10> digits{
        "Zero", "One", "Two",   "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine"};
    static const std::array<std::string, 10> teens{
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    static const std::array<std::string, 10> tens{
        "Zero",  "Ten",   "Twenty",  "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    static const std::array<std::pair<std::string, int>, 4> large{{
        {"Billion", 1'000'000'000},
        {"Million", 1'000'000},
        {"Thousand", 1'000},
        {"Hundred", 100},
    }};

    if (num < 10) {
      return digits[num];
    }
    if (num < 20) {
      return teens[num - 10];
    }
    if (num < 100) {
      if (num % 10) {
        return tens[num / 10] + " " + digits[num % 10];
      }
      return tens[num / 10];
    }

    for (const auto &[s, n] : large) {
      if (num >= n) {
        return numberToWords(num / n) + " " + s +
               (num % n ? " " + numberToWords(num % n) : "");
      }
    }

    throw;
  }
};
