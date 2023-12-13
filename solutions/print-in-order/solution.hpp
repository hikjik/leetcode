#pragma once

#include <functional>
#include <mutex>

// Time: O(1)
// Space: O(1)

class Foo {
public:
  Foo() {
    m1.lock();
    m2.lock();
  }

  void first(std::function<void()> printFirst) {
    printFirst();
    m1.unlock();
  }

  void second(std::function<void()> printSecond) {
    std::lock_guard guard(m1);
    printSecond();
    m2.unlock();
  }

  void third(std::function<void()> printThird) {
    std::lock_guard guard(m2);
    printThird();
  }

private:
  std::mutex m1, m2;
};
