#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 2;
    std::vector<int> prices{2, 4, 1};
    REQUIRE(2 == Solution::maxProfit(k, prices));
  }
  {
    int k = 2;
    std::vector<int> prices{3, 2, 6, 5, 0, 3};
    REQUIRE(7 == Solution::maxProfit(k, prices));
  }
  {
    int k = 2;
    std::vector<int> prices{1};
    REQUIRE(0 == Solution::maxProfit(k, prices));
  }
}
