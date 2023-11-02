#pragma once

#include <string>
#include <vector>

// Time:
// Space:

class OrderedStream {
public:
  OrderedStream(int n) : values_(n), pos_(0) {}

  std::vector<std::string> insert(int idKey, std::string value) {
    values_[idKey - 1] = value;
    std::vector<std::string> chunk;
    while (pos_ < values_.size() && !values_[pos_].empty()) {
      chunk.push_back(values_[pos_++]);
    }
    return chunk;
  }

private:
  std::vector<std::string> values_;
  size_t pos_;
};
