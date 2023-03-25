#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> points{{1, 1}, {2, 2}, {3, 3}};
    REQUIRE(3 == Solution::maxPoints(points));
  }
  {
    std::vector<std::vector<int>> points{{1, 1}, {3, 2}, {5, 3},
                                         {4, 1}, {2, 3}, {1, 4}};
    REQUIRE(4 == Solution::maxPoints(points));
  }
  {
    std::vector<std::vector<int>> points{{0, 0}};
    REQUIRE(1 == Solution::maxPoints(points));
  }
  {
    std::vector<std::vector<int>> points{{1, 0}, {0, 0}};
    REQUIRE(2 == Solution::maxPoints(points));
  }
}