#pragma once

#include <random>
#include <string>
#include <unordered_map>

// Time: O(NM)
// Space: O(NM)

class Solution {
public:
  Solution(uint32_t seed = 42u) : generator(seed) {}

  // O(N)
  std::string encode(std::string longUrl) {
    while (!urlToCode.contains(longUrl)) {
      const auto code = GenString(10);
      if (codeToUrl.contains(code)) {
        continue;
      }
      codeToUrl[code] = longUrl;
      urlToCode[longUrl] = code;
    }
    return kURL + urlToCode[longUrl];
  }

  // O(N)
  std::string decode(std::string shortUrl) {
    return codeToUrl[shortUrl.substr(kURL.size())];
  }

private:
  static const inline std::string kURL = "http://tinyurl.com/";

  std::string GenString(size_t size) {
    static const std::string kAlphabet =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::uniform_int_distribution<int> dist(0, kAlphabet.size() - 1);

    std::string result(size, '0');
    for (char &x : result) {
      x = kAlphabet[dist(generator)];
    }
    return result;
  }

  std::mt19937 generator;
  std::unordered_map<std::string, std::string> urlToCode;
  std::unordered_map<std::string, std::string> codeToUrl;
};
