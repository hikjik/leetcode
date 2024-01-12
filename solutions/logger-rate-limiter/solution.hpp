#pragma once

#include <string>
#include <unordered_map>

// Time: O(Q)
// Space: O(Q)

class Logger {
public:
  bool shouldPrintMessage(int timestamp, std::string message) {
    if (!seen.contains(message) || timestamp - seen[message] >= 10) {
      seen[message] = timestamp;
      return true;
    }
    return false;
  }

private:
  std::unordered_map<std::string, int> seen;
};
