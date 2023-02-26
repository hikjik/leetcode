#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> prices{1, 3, 2, 8, 4, 9};
    int fee = 2;
    REQUIRE(8 == Solution::maxProfit(prices, fee));
  }
  {
    std::vector<int> prices{1, 3, 7, 5, 10, 3};
    int fee = 3;
    REQUIRE(6 == Solution::maxProfit(prices, fee));
  }
}
