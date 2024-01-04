#pragma once

#include <vector>

// Time: O(N^2)
// Space: O(1)

class CategoryHandler {
public:
  explicit CategoryHandler(std::vector<int> categories)
      : categories(std::move(categories)) {}

  bool haveSameCategory(int a, int b) const {
    return categories[a] == categories[b];
  }

private:
  std::vector<int> categories;
};

class Solution {
public:
  static int numberOfCategories(int n, CategoryHandler *categoryHandler) {
    int ans = n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (categoryHandler->haveSameCategory(i, j)) {
          --ans;
          break;
        }
      }
    }
    return ans;
  }
};
