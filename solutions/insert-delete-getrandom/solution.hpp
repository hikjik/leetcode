#pragma once

#include <unordered_map>
#include <vector>

class RandomizedSet {
public:
  RandomizedSet() {}

  bool insert(int val) {
    if (indexes_.count(val)) {
      return false;
    }

    indexes_[val] = values_.size();
    values_.push_back(val);

    return true;
  }

  bool remove(int val) {
    auto it = indexes_.find(val);
    if (it == indexes_.end()) {
      return false;
    }

    indexes_[values_.back()] = it->second;
    values_[it->second] = values_.back();
    values_.pop_back();
    indexes_.erase(val);
    return true;
  }

  int getRandom() {
    const auto index = rand() % values_.size();
    return values_[index];
  }

private:
  std::vector<int> values_;
  std::unordered_map<int, size_t> indexes_;
};
