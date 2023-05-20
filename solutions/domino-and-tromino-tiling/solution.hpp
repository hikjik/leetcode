#pragma once

#include <tuple>

class Solution {
private:
  static const int kMod = 1e9 + 7;

public:
  static int numTilings(int n) {
    int d0 = 1, d1 = 1, q = 0;
    while (--n) {
      std::tie(d0, d1, q) =
          std::make_tuple(d1, (d0 + d1 + 2LL * q) % kMod, (q + d0) % kMod);
    }
    return d1;
  }
};
