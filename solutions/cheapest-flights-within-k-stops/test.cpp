#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 4;
    std::vector<std::vector<int>> flights{
        {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dst = 3, k = 1;
    REQUIRE(700 == Solution::findCheapestPrice(n, flights, src, dst, k));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> flights{
        {0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0, dst = 2, k = 1;
    REQUIRE(200 == Solution::findCheapestPrice(n, flights, src, dst, k));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> flights{
        {0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0, dst = 2, k = 0;
    REQUIRE(500 == Solution::findCheapestPrice(n, flights, src, dst, k));
  }
}
