#pragma once

#include <algorithm>
#include <string>
#include <vector>

// Time:
// Space:

class Solution {
private:
  static const size_t topK = 3;

public:
  static std::vector<std::vector<std::string>>
  suggestedProducts(std::vector<std::string> products,
                    const std::string &searchWord) {
    std::sort(products.begin(), products.end());

    std::vector<std::vector<std::string>> suggested_products;
    for (size_t i = 1; i <= searchWord.size(); ++i) {
      suggested_products.emplace_back();

      auto lb = std::lower_bound(products.begin(), products.end(),
                                 searchWord.substr(0, i));
      for (size_t j = 0; j < topK && lb != products.end(); ++j, ++lb) {
        if (lb->find(searchWord.substr(0, i)) == std::string::npos) {
          break;
        }
        suggested_products.back().push_back(*lb);
      }
    }
    return suggested_products;
  }
};
