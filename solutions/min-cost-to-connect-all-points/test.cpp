#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> points{
        {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    REQUIRE(20 == Solution::minCostConnectPoints(points));
  }
  {
    std::vector<std::vector<int>> points{{3, 12}, {-2, 5}, {-4, 1}};
    REQUIRE(18 == Solution::minCostConnectPoints(points));
  }
}
