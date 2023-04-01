#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<int> gas{1, 2, 3, 4, 5};
    std::vector<int> cost{3, 4, 5, 1, 2};
    REQUIRE(3 == Solution::canCompleteCircuit(gas, cost));
  }
  {
    std::vector<int> gas{2, 3, 4};
    std::vector<int> cost{3, 4, 3};
    REQUIRE(-1 == Solution::canCompleteCircuit(gas, cost));
  }
  {
    std::vector<int> gas{4, 5, 2, 6, 5, 3};
    std::vector<int> cost{3, 2, 7, 3, 2, 9};
    REQUIRE(-1 == Solution::canCompleteCircuit(gas, cost));
  }
}