#pragma once

#include <initializer_list>
#include <vector>

class ImmutableListNode {
public:
  void printValue() { out->push_back(val); }

  ImmutableListNode *getNext() { return next; }

  ImmutableListNode() : out(nullptr), val(0), next(nullptr) {}
  ImmutableListNode(std::vector<int> *out, int x)
      : out(out), val(x), next(nullptr) {}
  ImmutableListNode(std::vector<int> *out, int x, ImmutableListNode *next)
      : out(out), val(x), next(next) {}

private:
  friend class ImmutableList;

  std::vector<int> *out;
  int val;
  ImmutableListNode *next;
};

class ImmutableList {
public:
  ImmutableList() {}

  ImmutableList(std::initializer_list<int> lst) {
    auto *tail = &dummy_;
    for (auto val : lst) {
      tail = tail->next = new ImmutableListNode(&out_, val);
    }
  }

  ImmutableList(const ImmutableList &other) {
    out_ = other.out_;

    auto *copy = &dummy_;
    for (auto *node = other.dummy_.next; node; node = node->next) {
      copy = copy->next = new ImmutableListNode(&out_, node->val);
    }
  }

  const std::vector<int> &getPrintResults() const { return out_; }

  ~ImmutableList() {
    auto node = dummy_.next;
    while (node) {
      auto next = node->next;
      delete node;
      node = next;
    }
  }

  operator ImmutableListNode *() const { return dummy_.next; }

private:
  ImmutableListNode dummy_;
  std::vector<int> out_;
};
