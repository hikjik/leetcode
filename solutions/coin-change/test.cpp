#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> coins{1, 2, 5};
    int amount = 11;
    REQUIRE(3 == Solution::coinChange(coins, amount));
  }
  {
    std::vector<int> coins{2};
    int amount = 3;
    REQUIRE(-1 == Solution::coinChange(coins, amount));
  }
  {
    std::vector<int> coins{1};
    int amount = 0;
    REQUIRE(0 == Solution::coinChange(coins, amount));
  }
}
