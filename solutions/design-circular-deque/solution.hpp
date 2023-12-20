#pragma once

#include <vector>

// Time: O(Q)
// Space: O(K)

class MyCircularDeque {
public:
  explicit MyCircularDeque(int k)
      : data(k), capacity(k), size(0), head(0), tail(k - 1) {}

  bool insertFront(int value) {
    if (isFull()) {
      return false;
    }
    head = (head + capacity - 1) % capacity;
    data[head] = value;
    ++size;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) {
      return false;
    }
    tail = (tail + 1) % capacity;
    data[tail] = value;
    ++size;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) {
      return false;
    }
    head = (head + 1) % capacity;
    --size;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) {
      return false;
    }
    tail = (tail + capacity - 1) % capacity;
    --size;
    return true;
  }

  int getFront() const { return isEmpty() ? -1 : data[head]; }

  int getRear() const { return isEmpty() ? -1 : data[tail]; }

  bool isEmpty() const { return size == 0; }

  bool isFull() const { return size == capacity; }

private:
  std::vector<int> data;
  int capacity;
  int size;
  int head;
  int tail;
};
