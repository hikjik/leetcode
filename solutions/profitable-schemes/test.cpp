#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 5, minProfit = 3;
    std::vector<int> group{2, 2};
    std::vector<int> profit{2, 3};
    REQUIRE(2 == Solution::profitableSchemes(n, minProfit, group, profit));
  }
  {
    int n = 10, minProfit = 5;
    std::vector<int> group{2, 3, 5};
    std::vector<int> profit{6, 7, 8};
    REQUIRE(7 == Solution::profitableSchemes(n, minProfit, group, profit));
  }
}
