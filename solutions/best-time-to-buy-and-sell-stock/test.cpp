#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    REQUIRE(5 == Solution::maxProfit(prices));
  }
  {
    std::vector<int> prices{7, 6, 4, 3, 1};
    REQUIRE(0 == Solution::maxProfit(prices));
  }
}
