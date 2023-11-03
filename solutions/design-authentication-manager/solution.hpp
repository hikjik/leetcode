#pragma once

#include <string>
#include <unordered_map>

// Time:
// Space:

class AuthenticationManager {
public:
  AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {}

  void generate(std::string tokenId, int currentTime) {
    tokens[tokenId] = currentTime + timeToLive;
  }

  void renew(std::string tokenId, int currentTime) {
    if (auto it = tokens.find(tokenId);
        it != tokens.end() && it->second > currentTime) {
      it->second = currentTime + timeToLive;
    }
  }

  int countUnexpiredTokens(int currentTime) {
    int count = 0;
    for (auto it = tokens.begin(); it != tokens.cend();) {
      if (it->second <= currentTime) {
        tokens.erase(it++);
      } else {
        ++it;
        ++count;
      }
    }
    return count;
  }

private:
  std::unordered_map<std::string, int> tokens;
  int timeToLive;
};
