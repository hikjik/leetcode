#pragma once

#include <optional>
#include <unordered_map>
#include <vector>

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

Node *Copy(Node *head) {
  std::unordered_map<Node *, Node *> map;

  Node dummy(0);
  for (auto copy = &dummy, node = head; node; node = node->next) {
    copy = copy->next = new Node(node->val);
    map[node] = copy;
  }

  for (auto node = head; node; node = node->next) {
    if (node->random) {
      map[node]->random = map[node->random];
    }
  }

  return dummy.next;
}

class List {
public:
  List() : dummy_(0) {}

  List(const List &other) : List() { dummy_.next = Copy(other.dummy_.next); }

  List(List &&other) : List() { Swap(other); }

  List &operator=(List other) {
    Swap(other);
    return *this;
  }

  void Swap(List &other) { std::swap(dummy_, other.dummy_); }

  List(std::initializer_list<std::pair<int, std::optional<int>>> list)
      : List() {
    std::vector values(list.begin(), list.end());

    const int n = values.size();
    std::vector<Node *> nodes(n, nullptr);

    auto node = &dummy_;
    for (int i = 0; i < n; ++i) {
      node->next = new Node(values[i].first);
      node = node->next;
      nodes[i] = node;
    }

    for (int i = 0; i < n; ++i) {
      if (values[i].second) {
        const auto index = values[i].second.value();
        nodes[i]->random = nodes[index];
      }
    }
  }

  List(Node *head) : List() { dummy_.next = head; }

  ~List() {
    auto node = dummy_.next;
    while (node) {
      auto next = node->next;
      delete node;
      node = next;
    }
  }

  operator Node *() const { return dummy_.next; }

  friend bool operator==(const List &lhs, const List &rhs) {
    std::unordered_map<Node *, Node *> map;

    auto h1 = lhs.dummy_.next, h2 = rhs.dummy_.next;
    while (h1 && h2) {
      map[h1] = h2;

      if (h1->val != h2->val) {
        return false;
      }
      h1 = h1->next, h2 = h2->next;
    }
    if (h1 || h2) {
      return false;
    }

    h1 = lhs.dummy_.next, h2 = rhs.dummy_.next;
    while (h1 && h2) {
      if (map[h1->random] != h2->random) {
        return false;
      }

      h1 = h1->next, h2 = h2->next;
    }

    return true;
  }

private:
  Node dummy_;
};
