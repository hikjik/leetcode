#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    REQUIRE(6 == Solution::maxProfit(prices));
  }
  {
    std::vector<int> prices{1, 2, 3, 4, 5};
    REQUIRE(4 == Solution::maxProfit(prices));
  }
  {
    std::vector<int> prices{7, 6, 4, 3, 1};
    REQUIRE(0 == Solution::maxProfit(prices));
  }
}
