#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int source = 1, target = 6;
    std::vector<std::vector<int>> routes{{1, 2, 7}, {3, 6, 7}};
    REQUIRE(2 == Solution::numBusesToDestination(routes, source, target));
  }
  {
    int source = 15, target = 12;
    std::vector<std::vector<int>> routes{
        {7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
    REQUIRE(-1 == Solution::numBusesToDestination(routes, source, target));
  }
  {
    int source = 5, target = 5;
    std::vector<std::vector<int>> routes{{1, 7}, {3, 5}};
    REQUIRE(0 == Solution::numBusesToDestination(routes, source, target));
  }
  {
    int source = 1, target = 2;
    std::vector<std::vector<int>> routes{{1, 2}};
    REQUIRE(1 == Solution::numBusesToDestination(routes, source, target));
  }
}
