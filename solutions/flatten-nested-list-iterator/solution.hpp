#pragma once

#include <stack>
#include <variant>
#include <vector>

/*
  341. Flatten Nested List Iterator
  https://leetcode.com/problems/flatten-nested-list-iterator/
  Difficulty: Medium
  Tags: Stack, Tree, Depth-First Search, Design, Queue, Iterator
  Time:
  Space:
*/

class NestedInteger {
public:
  NestedInteger(std::vector<NestedInteger> variant)
      : variant_(std::move(variant)) {}

  NestedInteger(int variant) : variant_(variant) {}

  NestedInteger(std::initializer_list<NestedInteger> list) {
    variant_ = std::vector<NestedInteger>(list.begin(), list.end());
  }

  bool isInteger() const { return std::holds_alternative<int>(variant_); }

  int getInteger() const { return std::get<int>(variant_); }

  const std::vector<NestedInteger> &getList() const {
    return std::get<std::vector<NestedInteger>>(variant_);
  }

private:
  std::variant<int, std::vector<NestedInteger>> variant_;
};

class NestedIterator {
public:
  NestedIterator(const std::vector<NestedInteger> &nestedList) {
    pushList(nestedList);
  }

  int next() {
    auto top = stack_.top();
    stack_.pop();
    return top.getInteger();
  }

  bool hasNext() {
    while (!stack_.empty() && !stack_.top().isInteger()) {
      auto top = stack_.top();
      stack_.pop();
      pushList(top.getList());
    }

    return !stack_.empty();
  }

private:
  void pushList(const std::vector<NestedInteger> &nestedList) {
    for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
      stack_.push(*it);
    }
  }

  std::stack<NestedInteger> stack_;
};
