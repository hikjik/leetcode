#pragma once

#include <vector>

// Time: O(N+Q)
// Space: O(N)

class Bank {
public:
  // O(N)
  explicit Bank(std::vector<long long> balance) : balance(std::move(balance)) {}

  // O(1)
  bool transfer(int account1, int account2, long long money) {
    return exists(account2) && withdraw(account1, money) &&
           deposit(account2, money);
  }

  // O(1)
  bool deposit(int account, long long money) {
    if (!exists(account)) {
      return false;
    }
    balance[account - 1] += money;
    return true;
  }

  // O(1)
  bool withdraw(int account, long long money) {
    if (!exists(account) || balance[account - 1] < money) {
      return false;
    }
    balance[account - 1] -= money;
    return true;
  }

private:
  bool exists(int account) const {
    return 1 <= account && account <= std::ssize(balance);
  }

  std::vector<long long> balance;
};
