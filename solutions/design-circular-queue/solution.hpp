#pragma once

#include <vector>

// Time:
// Space:

class MyCircularQueue {
public:
  MyCircularQueue(int k) : data_(k), head_(0), size_(0) {}

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    data_[(head_ + size_++) % data_.size()] = value;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    head_ = (head_ + 1) % data_.size();
    size_--;
    return true;
  }

  int Front() { return isEmpty() ? -1 : data_[head_]; }

  int Rear() {
    return isEmpty() ? -1 : data_[(head_ + size_ - 1) % data_.size()];
  }

  bool isEmpty() { return size_ == 0; }

  bool isFull() { return size_ == data_.size(); }

private:
  std::vector<int> data_;
  size_t head_;
  size_t size_;
};
