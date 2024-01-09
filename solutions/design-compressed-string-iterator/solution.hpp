#pragma once

#include <sstream>
#include <string>

// Time:
// Space:

class StringIterator {
public:
  StringIterator(const std::string &compressedString)
      : sstream(compressedString) {}

  char next() {
    if (!hasNext()) {
      return ' ';
    }

    if (!cnt) {
      sstream >> curr >> cnt;
    }
    --cnt;
    return curr;
  }

  bool hasNext() const { return cnt || !sstream.eof(); }

private:
  std::stringstream sstream;
  char curr;
  int cnt = 0;
};
