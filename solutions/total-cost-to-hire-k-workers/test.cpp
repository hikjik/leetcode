#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int k = 3, candidates = 4;
    std::vector<int> costs{17, 12, 10, 2, 7, 2, 11, 20, 8};
    REQUIRE(11 == Solution::totalCost(costs, k, candidates));
  }
  {
    int k = 3, candidates = 3;
    std::vector<int> costs{1, 2, 4, 1};
    REQUIRE(4 == Solution::totalCost(costs, k, candidates));
  }
}
