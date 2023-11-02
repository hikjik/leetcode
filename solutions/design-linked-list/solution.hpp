#pragma once

// Time:
// Space:

class MyLinkedList {
private:
  struct ListNode {
    ListNode() : prev(nullptr), next(nullptr), val(0) {}

    ListNode(ListNode *prev, ListNode *next, int val)
        : prev(prev), next(next), val(val) {}

    ListNode *prev;
    ListNode *next;
    int val;
  };

  ListNode dummy;
  int size = 0;

  void insertBefore(ListNode *next, int val) {
    auto prev = next->prev;

    auto new_node = new ListNode(prev, next, val);
    prev->next = new_node;
    next->prev = new_node;
    size++;
  }

  void DeleteNode(ListNode *node) {
    auto next = node->next;
    auto prev = node->prev;

    prev->next = next;
    next->prev = prev;

    delete node;
    size--;
  }

public:
  MyLinkedList() { dummy.next = dummy.prev = &dummy; }
  ~MyLinkedList() {
    while (size) {
      DeleteNode(dummy.next);
    }
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }

    auto node = dummy.next;
    while (index--) {
      node = node->next;
    }
    return node->val;
  }

  void addAtHead(int val) { insertBefore(dummy.next, val); }

  void addAtTail(int val) { insertBefore(&dummy, val); }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size) {
      return;
    }
    auto next = dummy.next;
    while (index--) {
      next = next->next;
    }
    insertBefore(next, val);
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      return;
    }
    auto node = dummy.next;
    while (index--) {
      node = node->next;
    }

    DeleteNode(node);
  }
};
