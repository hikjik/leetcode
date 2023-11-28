#pragma once

#include <ranges>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int minPartitions(std::string n) { return std::ranges::max(n) - '0'; }
};
