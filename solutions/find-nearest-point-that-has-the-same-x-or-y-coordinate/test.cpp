#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int x = 3;
    int y = 4;
    std::vector<std::vector<int>> points{
        {1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
    REQUIRE(2 == Solution::nearestValidPoint(x, y, points));
  }
  {
    int x = 3;
    int y = 4;
    std::vector<std::vector<int>> points{{3, 4}};
    REQUIRE(0 == Solution::nearestValidPoint(x, y, points));
  }
  {
    int x = 3;
    int y = 4;
    std::vector<std::vector<int>> points{{2, 3}};
    REQUIRE(-1 == Solution::nearestValidPoint(x, y, points));
  }
}
