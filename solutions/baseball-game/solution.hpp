#pragma once

#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  static int calPoints(const std::vector<std::string> &operations) {
    std::vector<int> scores;
    for (const auto &op : operations) {
      if (op == "C") {
        scores.pop_back();
      } else if (op == "D") {
        scores.push_back(2 * scores.back());
      } else if (op == "+") {
        scores.push_back(scores.back() + scores[scores.size() - 2]);
      } else {
        scores.push_back(std::stoi(op));
      }
    }
    return std::accumulate(scores.begin(), scores.end(), 0);
  }
};
