#pragma once

#include <initializer_list>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *Copy(ListNode *head) {
  ListNode dummy;
  for (auto copy = &dummy, node = head; node; node = node->next) {
    copy = copy->next = new ListNode(node->val);
  }
  return dummy.next;
}

ListNode *Find(ListNode *head, int value) {
  auto node = head;
  while (node && node->val != value) {
    node = node->next;
  }
  return node;
}

class List {
public:
  List() {}

  List(const List &other) : List() { dummy_.next = Copy(other.dummy_.next); }

  List(List &&other) : List() { Swap(other); }

  List(std::initializer_list<int> list) : List() {
    auto tail = &dummy_;
    for (auto val : list) {
      tail = tail->next = new ListNode(val);
    }
  }

  List(ListNode *head) { dummy_.next = head; }

  List &operator=(List other) {
    Swap(other);
    return *this;
  }

  void Swap(List &other) { std::swap(dummy_, other.dummy_); }

  ~List() {
    auto node = dummy_.next;
    while (node) {
      auto next = node->next;
      delete node;
      node = next;
    }
  }

  friend bool operator==(const List &lhs, const List &rhs) {
    auto h1 = lhs.dummy_.next, h2 = rhs.dummy_.next;
    while (h1 && h2) {
      if (h1->val != h2->val) {
        return false;
      }
      h1 = h1->next, h2 = h2->next;
    }
    return !h1 && !h2;
  }

  operator ListNode *() const { return dummy_.next; }

private:
  ListNode dummy_;
};
