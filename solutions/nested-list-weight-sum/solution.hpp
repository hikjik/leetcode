#pragma once

#include <variant>
#include <vector>

// Time: O(N)
// Space: O(N)

class NestedInteger {
public:
  NestedInteger(std::vector<NestedInteger> array) : data(std::move(array)) {}

  NestedInteger(int value) : data(value) {}

  NestedInteger(std::initializer_list<NestedInteger> list)
      : data(std::vector<NestedInteger>(list.begin(), list.end())) {}

  bool isInteger() const { return std::holds_alternative<int>(data); }

  int getInteger() const { return std::get<int>(data); }

  const std::vector<NestedInteger> &getList() const {
    return std::get<std::vector<NestedInteger>>(data);
  }

private:
  std::variant<int, std::vector<NestedInteger>> data;
};

class Solution {
public:
  static int depthSum(const std::vector<NestedInteger> &nestedList,
                      int depth = 1) {
    int ans = 0;
    for (const auto &in : nestedList) {
      if (in.isInteger()) {
        ans += depth * in.getInteger();
      } else {
        ans += depthSum(in.getList(), depth + 1);
      }
    }
    return ans;
  }
};
