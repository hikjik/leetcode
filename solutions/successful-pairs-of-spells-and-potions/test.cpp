#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    long long success = 7;
    std::vector<int> spells{5, 1, 3};
    std::vector<int> potions{1, 2, 3, 4, 5};
    std::vector<int> expected{4, 0, 3};
    REQUIRE(expected == Solution::successfulPairs(spells, potions, success));
  }
  {
    long long success = 16;
    std::vector<int> spells{3, 1, 2};
    std::vector<int> potions{8, 5, 8};
    std::vector<int> expected{2, 0, 2};
    REQUIRE(expected == Solution::successfulPairs(spells, potions, success));
  }
}
