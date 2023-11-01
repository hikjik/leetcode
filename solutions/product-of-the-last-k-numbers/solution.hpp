#pragma once

#include <vector>

/*
  1352. Product of the Last K Numbers
  https://leetcode.com/problems/product-of-the-last-k-numbers/
  Difficulty: Medium
  Tags: Array, Math, Design, Queue, Data Stream
  Time:
  Space:
*/

class ProductOfNumbers {
private:
  std::vector<int> prefix;

public:
  ProductOfNumbers() {}

  void add(int num) {
    if (!num) {
      prefix.clear();
    } else if (prefix.empty()) {
      prefix.push_back(num);
    } else {
      prefix.push_back(num * prefix.back());
    }
  }

  int getProduct(int k) {
    int n = prefix.size();
    if (k > n) {
      return 0;
    }
    if (k == n) {
      return prefix.back();
    }
    return prefix.back() / prefix[n - k - 1];
  }
};
