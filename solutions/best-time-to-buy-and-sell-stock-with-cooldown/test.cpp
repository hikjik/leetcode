#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> prices{1, 2, 3, 0, 2};
    REQUIRE(3 == Solution::maxProfit(prices));
  }
  {
    std::vector<int> prices{1};
    REQUIRE(0 == Solution::maxProfit(prices));
  }
}
