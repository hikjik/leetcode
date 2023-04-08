#pragma once

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class TimeMap {
private:
  struct Item {
    int timestamp;
    std::string value;
  };

  std::unordered_map<std::string, std::vector<Item>> data_;

public:
  void set(std::string key, std::string value, int timestamp) {
    data_[key].push_back({timestamp, value});
  }

  std::string get(std::string key, int timestamp) {
    if (!data_.count(key)) {
      return "";
    }
    const auto &items = data_[key];
    auto compare = [](int timestamp, const Item &item) {
      return timestamp < item.timestamp;
    };
    auto ub = std::upper_bound(items.begin(), items.end(), timestamp, compare);
    return ub == items.begin() ? "" : std::prev(ub)->value;
  }
};
