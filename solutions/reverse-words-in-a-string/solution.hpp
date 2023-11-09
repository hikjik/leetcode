#pragma once

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

// Time: O(N)
// Space: O(1)

namespace stream {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::string reverseWords(std::string s) {
    std::istringstream istream(s);
    std::vector<std::string> buffer{std::istream_iterator<std::string>(istream),
                                    std::istream_iterator<std::string>()};
    std::ostringstream ostream;
    std::copy(buffer.rbegin(), std::prev(buffer.rend()),
              std::ostream_iterator<std::string>(ostream, " "));
    return ostream.str() + buffer.front();
  }
};

} // namespace stream

namespace inplace {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static std::string reverseWords(std::string s) {
    s.erase(std::unique(s.begin(), s.end(),
                        [](char a, char b) { return a == ' ' && b == ' '; }),
            s.end());
    s.erase(s.find_last_not_of(' ') + 1);
    std::reverse(s.begin(), s.end());
    s.erase(s.find_last_not_of(' ') + 1);
    auto first = s.begin();
    for (auto last = s.begin(); last != s.end(); ++last) {
      if (*last == ' ') {
        std::reverse(first, last);
        first = std::next(last);
      }
    }
    std::reverse(first, s.end());
    return s;
  }
};

} // namespace inplace
