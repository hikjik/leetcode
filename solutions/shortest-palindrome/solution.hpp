#pragma once

#include <ranges>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace brute_force {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static std::string shortestPalindrome(std::string s) {
    std::string r(s);
    std::ranges::reverse(r);
    std::string_view sv(s), rv(r);
    const int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (sv.substr(0, n - i) == rv.substr(i)) {
        return r.substr(0, i) + s;
      }
    }
    return "";
  }
};

} // namespace brute_force

namespace recursive {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static std::string shortestPalindrome(std::string s) {
    const int n = s.size();
    int i = 0;
    for (int j = n - 1; j >= 0; --j) {
      if (s[i] == s[j]) {
        i++;
      }
    }
    if (i == n) {
      return s;
    }
    std::string suffix = s.substr(i, n);
    std::ranges::reverse(suffix);
    return suffix + shortestPalindrome(s.substr(0, i)) + s.substr(i);
  }
};

} // namespace recursive

namespace rolling_hash {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::string shortestPalindrome(std::string s) {
    if (s.empty()) {
      return s;
    }

    const int prime = 31;
    const int modulus = 1e9 + 9;

    long long prime_pow = 1;
    long long hash_forward = 0, hash_backward = 0;
    int index = 0;
    for (int i = 0; i < std::ssize(s); ++i) {
      hash_forward = (hash_forward + (s[i] - 'a') * prime_pow) % modulus;
      hash_backward = (hash_backward * prime + (s[i] - 'a')) % modulus;
      if (hash_forward == hash_backward) {
        index = i;
      }
      prime_pow = (prime_pow * prime) % modulus;
    }

    auto suffix = s.substr(index + 1);
    std::ranges::reverse(suffix);
    return suffix + s;
  }
};

} // namespace rolling_hash

namespace kmp {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::string shortestPalindrome(std::string s) {
    auto r = s;
    std::ranges::reverse(r);
    const auto lsp = LPS(s + "#" + r);
    return r.substr(0, s.size() - lsp.back()) + s;
  }

private:
  static std::vector<int> LPS(const std::string &str) {
    std::vector<int> lps(str.size(), 0);
    for (size_t i = 1; i < str.size(); ++i) {
      int j = lps[i - 1];
      while (j && str[j] != str[i]) {
        j = lps[j - 1];
      }
      if (str[i] == str[j]) {
        ++j;
      }
      lps[i] = j;
    }
    return lps;
  }
};

} // namespace kmp

namespace manacher {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::string shortestPalindrome(std::string s) {
    const int n = s.size();
    const auto p = manacher(s);
    for (int i = n - 1; i >= 0; --i) {
      if (isPalindrome(0, i, p)) {
        auto suffix = s.substr(i + 1);
        std::ranges::reverse(suffix);
        return suffix + s;
      }
    }
    return "";
  }

private:
  static bool isPalindrome(int i, int j, const std::vector<int> &p) {
    return p[i + j + 2] - 1 >= j - i + 1;
  }

  static std::vector<int> manacher(const std::string &s) {
    std::string t = "^";
    for (auto c : s) {
      t += '#', t += c;
    }
    t += '#', t += '$';

    std::vector<int> p(t.size());
    for (int i = 1, l = 1, r = 1; i < std::ssize(t) - 1; ++i) {
      const int j = l + r - i;
      p[i] = std::max(0, std::min(r - i, p[j]));

      while (t[i - p[i]] == t[i + p[i]]) {
        ++p[i];
      }

      if (i + p[i] > r) {
        l = i - p[i], r = i + p[i];
      }
    }
    return p;
  }
};

} // namespace manacher
