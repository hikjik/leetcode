#pragma once

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string reorderSpaces(std::string text) {
    std::vector<std::string> words;
    std::istringstream istream(text);
    std::copy(std::istream_iterator<std::string>(istream),
              std::istream_iterator<std::string>(), std::back_inserter(words));

    const auto spaces = std::count(text.begin(), text.end(), ' ');
    const auto q = words.size() > 1 ? spaces / (words.size() - 1) : 0;
    const auto r = words.size() > 1 ? spaces % (words.size() - 1) : spaces;
    const auto sep = std::string(q, ' ');
    const auto end = std::string(r, ' ');

    std::ostringstream ostream;
    std::copy(words.begin(), std::prev(words.end()),
              std::ostream_iterator<std::string>(ostream, sep.c_str()));
    return ostream.str() + words.back() + end;
  }
};
