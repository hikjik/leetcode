#pragma once

#include <unordered_map>
#include <vector>

// Time: O(M+QK)
// Space: O(M)

class Cashier {
public:
  // O(M), M = products.size()
  Cashier(int n, int discount, const std::vector<int> &products,
          const std::vector<int> &prices)
      : n(n), discount(discount) {
    for (int i = 0; i < std::ssize(products); ++i) {
      productsPrices[products[i]] = prices[i];
    }
  }

  // O(K), K = products.size()
  double getBill(const std::vector<int> product,
                 const std::vector<int> amount) {
    double bill = 0;
    for (int i = 0; i < std::ssize(product); ++i) {
      bill += amount[i] * productsPrices[product[i]];
    }
    return applyDiscount(bill);
  }

private:
  double applyDiscount(double bill) {
    if (++clock == n) {
      clock = 0;
      return bill * (100 - discount) / 100;
    }
    return bill;
  }

  int n;
  int discount;
  int clock = 0;
  std::unordered_map<int, int> productsPrices;
};
