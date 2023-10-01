#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int orders = 4;
    std::vector<int> inventory{2, 5};
    REQUIRE(14 == Solution::maxProfit(inventory, orders));
  }
  {
    int orders = 6;
    std::vector<int> inventory{3, 5};
    REQUIRE(19 == Solution::maxProfit(inventory, orders));
  }
}
